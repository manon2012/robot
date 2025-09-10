import grpc
from concurrent import futures
import time
from datetime import datetime
import greeter_pb2
import greeter_pb2_grpc
import socket

class GreeterServicer(greeter_pb2_grpc.GreeterServicer):
    def __init__(self):
        self.server_id = socket.gethostname()
        self.request_count = 0
    
    def SayHello(self, request, context):
        """Unary RPC - Single request, single response"""
        self.request_count += 1
        print(f"[{self.request_count}] Unary request from: {request.name} (age: {request.age})")
        
        # Create response
        response = greeter_pb2.HelloReply()
        response.message = f"Hello, {request.name}! You are {request.age} years old."
        response.timestamp = datetime.now().isoformat()
        response.server_id = self.server_id
        
        return response
    
    def SayHelloStream(self, request, context):
        """Server streaming RPC - Single request, multiple responses"""
        self.request_count += 1
        print(f"[{self.request_count}] Streaming request from: {request.name}")
        
        # Send multiple responses over time
        for i in range(5):
            if context.is_active():  # Check if client is still connected
                response = greeter_pb2.HelloReply()
                response.message = f"Hello {request.name}! This is message #{i+1}"
                response.timestamp = datetime.now().isoformat()
                response.server_id = self.server_id
                
                yield response
                time.sleep(1)  # Simulate processing time
            else:
                break
    
    def SayHelloToMany(self, request_iterator, context):
        """Client streaming RPC - Multiple requests, single response"""
        self.request_count += 1
        names = []
        total_age = 0
        count = 0
        
        # Process stream of incoming requests
        for request in request_iterator:
            names.append(request.name)
            total_age += request.age
            count += 1
            print(f"Received: {request.name} (age: {request.age})")
        
        # Create final response
        response = greeter_pb2.HelloReply()
        response.message = f"Hello to {count} people! Average age: {total_age/count:.1f}"
        response.timestamp = datetime.now().isoformat()
        response.server_id = self.server_id
        
        print(f"Processed {count} requests from client streaming")
        return response
    
    def Chat(self, request_iterator, context):
        """Bidirectional streaming RPC - Multiple requests, multiple responses"""
        self.request_count += 1
        message_count = 0
        
        # Process incoming stream and send responses
        for request in request_iterator:
            message_count += 1
            print(f"Chat received [{message_count}]: {request.name}")
            
            # Create response for each request
            response = greeter_pb2.HelloReply()
            response.message = f"Echo #{message_count}: {request.name}"
            response.timestamp = datetime.now().isoformat()
            response.server_id = self.server_id
            
            yield response

def serve():
    # Create a gRPC server with thread pool
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    
    # Add our service implementation to the server
    greeter_pb2_grpc.add_GreeterServicer_to_server(GreeterServicer(), server)
    
    # Listen on port 50051
    server.add_insecure_port('[::]:50051')
    
    # Start the server
    server.start()
    print("gRPC Server started on port 50051")
    print("Server ID:", socket.gethostname())
    print("Press Ctrl+C to stop...")
    
    # Keep the server running
    try:
        while True:
            time.sleep(86400)  # One day
    except KeyboardInterrupt:
        print("\nShutting down server...")
        server.stop(0)

if __name__ == '__main__':
    serve()