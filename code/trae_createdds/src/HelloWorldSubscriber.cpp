// HelloWorldSubscriber.cpp - DDS Subscriber example
#include "HelloWorld.h"
#include "HelloWorldPubSubTypes.h"

#include <fastrtps/Domain.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/subscriber/SubscriberListener.h>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

std::atomic<bool> g_received{false};

class HelloWorldSubscriberListener : public SubscriberListener
{
public:
    void onSubscriptionMatched(Subscriber* /*subscriber*/, MatchingInfo& info) override
    {
        if (info.status == MATCHED_MATCHING)
        {
            std::cout << "[Subscriber] Publisher matched!" << std::endl;
        }
        else
        {
            std::cout << "[Subscriber] Publisher unmatched." << std::endl;
        }
    }

    void onNewDataMessage(Subscriber* subscriber) override
    {
        HelloWorld data;
        SampleInfo_t info;

        while (subscriber->takeNextData(&data, &info))
        {
            if (info.sampleKind == ALIVE)
            {
                std::cout << "[Subscriber] Received: " << data.message()
                          << " (index=" << data.index() << ")" << std::endl;
                g_received = true;
            }
        }
    }
};

int main()
{
    // 1. Create Participant
    ParticipantAttributes PParam;
    PParam.domainId = 0;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    PParam.rtps.setName("SubscriberParticipant");

    Participant* participant = Domain::createParticipant(PParam);
    if (participant == nullptr)
    {
        std::cerr << "Failed to create participant!" << std::endl;
        return -1;
    }

    // 2. Register Type
    HelloWorldPubSubType myType;
    Domain::registerType(participant, &myType);

    // 3. Create Subscriber
    SubscriberAttributes Rparam;
    Rparam.topic.topicKind = NO_KEY;
    Rparam.topic.topicDataType = "HelloWorld";
    Rparam.topic.topicName = "HelloWorldTopic";

    HelloWorldSubscriberListener listener;
    Subscriber* subscriber = Domain::createSubscriber(participant, Rparam, &listener);
    if (subscriber == nullptr)
    {
        std::cerr << "Failed to create subscriber!" << std::endl;
        Domain::removeParticipant(participant);
        return -1;
    }

    std::cout << "[Subscriber] Started. Waiting for messages..." << std::endl;

    // Wait for messages for a while
    std::this_thread::sleep_for(std::chrono::seconds(10));

    if (!g_received)
    {
        std::cout << "[Subscriber] No messages received." << std::endl;
    }

    // 4. Cleanup
    Domain::removeSubscriber(subscriber);
    Domain::removeParticipant(participant);

    std::cout << "[Subscriber] Shutting down." << std::endl;
    return 0;
}
