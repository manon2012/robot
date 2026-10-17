// HelloWorldPublisher.cpp - DDS Publisher example
#include "HelloWorld.h"
#include "HelloWorldPubSubTypes.h"

#include <fastrtps/Domain.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/publisher/PublisherListener.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>

#include <iostream>
#include <thread>
#include <chrono>

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

class HelloWorldPublisherListener : public PublisherListener
{
public:
    void onPublicationMatched(Publisher* /*publisher*/, MatchingInfo& info) override
    {
        if (info.status == MATCHED_MATCHING)
        {
            std::cout << "[Publisher] Subscriber matched!" << std::endl;
        }
        else
        {
            std::cout << "[Publisher] Subscriber unmatched." << std::endl;
        }
    }
};

int main()
{
    // 1. Create Participant
    ParticipantAttributes PParam;
    PParam.domainId = 0;
    PParam.rtps.builtin.discovery_config.leaseDuration = c_TimeInfinite;
    PParam.rtps.setName("PublisherParticipant");

    Participant* participant = Domain::createParticipant(PParam);
    if (participant == nullptr)
    {
        std::cerr << "Failed to create participant!" << std::endl;
        return -1;
    }

    // 2. Register Type
    HelloWorldPubSubType myType;
    Domain::registerType(participant, &myType);

    // 3. Create Publisher
    PublisherAttributes Wparam;
    Wparam.topic.topicKind = NO_KEY;
    Wparam.topic.topicDataType = "HelloWorld";
    Wparam.topic.topicName = "HelloWorldTopic";

    HelloWorldPublisherListener listener;
    Publisher* publisher = Domain::createPublisher(participant, Wparam, &listener);
    if (publisher == nullptr)
    {
        std::cerr << "Failed to create publisher!" << std::endl;
        Domain::removeParticipant(participant);
        return -1;
    }

    std::cout << "[Publisher] Started. Waiting for subscriber..." << std::endl;

    // Wait for subscriber to match
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // 4. Publish messages
    HelloWorld data;
    for (int i = 0; i < 10; ++i)
    {
        std::string msg = "Hello DDS World! count=" + std::to_string(i);
        data.message(msg);
        data.index(i);

        publisher->write(&data);
        std::cout << "[Publisher] Sent: " << data.message() << " (index=" << data.index() << ")" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "[Publisher] Done publishing." << std::endl;

    // 5. Cleanup
    Domain::removePublisher(publisher);
    Domain::removeParticipant(participant);

    return 0;
}
