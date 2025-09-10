import grpc
import greeter_pb2
import greeter_pb2_grpc
import time
from datetime import datetime

def run_unary_rpc(stub):
    """Example of unary RPC call - Single request, single response"""
    print("=== Unary RPC Example ===")
    
    # Create a request
    request = greeter_pb2.HelloRequest(name="Alice", age=25)
    
    # Make the RPC call with timeout
    try:
        response = stub.SayHello(request, timeout=10)
        print(f"✅ Response: {response.message}")
        print(f"   Timestamp: {response.timestamp}")
        print(f"   Server: {response.server_id}")
    except grpc.RpcError as e:
        print(f"❌ RPC failed: {e.code()} - {e.details()}")
    print()

def run_server_streaming(stub):
    """Example of server streaming RPC - Single request, multiple responses"""
    print("=== Server Streaming RPC Example ===")
    
    request = greeter_pb2.HelloRequest(name="Bob", age=30)
    
    try:
        # Get the stream of responses
        responses = stub.SayHelloStream(request, timeout=15)
        
        for i, response in enumerate(responses, 1):
            print(f"📨 Stream response #{i}: {response.message}")
            print(f"   Timestamp: {response.timestamp}")
    except grpc.RpcError as e:
        print(f"❌ Streaming failed: {e.code()} - {e.details()}")
    print()

def run_client_streaming(stub):
    """Example of client streaming RPC - Multiple requests, single response"""
    print("=== Client Streaming RPC Example ===")
    
    # Create a generator that yields multiple requests
    def generate_requests():
        people = [
            ("Charlie", 28),
            ("David", 35),
            ("Eve", 22),
            ("Frank", 40)
        ]
        
        for name, age in people:
            request = greeter_pb2.HelloRequest(name=name, age=age)
            print(f"📤 Sending: {name} (age: {age})")
            yield request
            time.sleep(0.5)  # Simulate time between requests
    
    try:
        # Make the streaming call
        response = stub.SayHelloToMany(generate_requests(), timeout=20)
        print(f"✅ Final response: {response.message}")
        print(f"   Timestamp: {response.timestamp}")
        print(f"   Server: {response.server_id}")
    except grpc.RpcError as e:
        print(f"❌ Client streaming failed: {e.code()} - {e.details()}")
    print()

def run_bidirectional_streaming(stub):
    """Example of bidirectional streaming RPC - Multiple requests, multiple responses"""
    print("=== Bidirectional Streaming RPC Example ===")
    
    # Create a generator for requests
    def generate_requests():
        messages = ["Hello", "How are you?", "What's your name?", "Goodbye"]
        
        for msg in messages:
            request = greeter_pb2.HelloRequest(name=msg, age=0)
            print(f"💬 Client sending: {msg}")
            yield request
            time.sleep(1)  # Wait before sending next message
    
    try:
        # Make the bidirectional call
        responses = stub.Chat(generate_requests(), timeout=20)
        
        for i, response in enumerate(responses, 1):
            print(f"🔁 Server responded #{i}: {response.message}")
            print(f"   Timestamp: {response.timestamp}")
    except grpc.RpcError as e:
        print(f"❌ Bidirectional streaming failed: {e.code()} - {e.details()}")
    print()

def main():
    # Create a channel to connect to the server
    print("Connecting to gRPC server...")
    channel = grpc.insecure_channel('localhost:50051')
    
    # Create a stub (client)
    stub = greeter_pb2_grpc.GreeterStub(channel)
    
    # Test connection with a simple call
    try:
        # Wait for channel to be ready (optional)
        grpc.channel_ready_future(channel).result(timeout=5)
        print("✅ Connected to server successfully!\n")
    except grpc.FutureTimeoutError:
        print("❌ Could not connect to server. Make sure server is running.")
        return
    
    # Run all examples
    run_unary_rpc(stub)
    time.sleep(1)
    
    run_server_streaming(stub)
    time.sleep(1)
    
    run_client_streaming(stub)
    time.sleep(1)
    
    run_bidirectional_streaming(stub)
    
    print("All examples completed! 🎉")

if __name__ == '__main__':
    main()