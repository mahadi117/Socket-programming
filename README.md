# hello-world
#Practising socket-programming in c language. 

I worked a bit to learn to make sockets and how they work. Revising a bit after a long time. 

Got help from this website.

http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

I think I should give some basic understanding of the socket programming about how it works

So a computer can communicate in networks using sockets. 
We can do socket programming in different programming languages.

Notable ones are Java, C, Python etc.



TCP/IP (Transmission Control Protocol/Internet Protocol) is the basic communication language or protocol of the Internet.Here the Server and Client need to have a connection established. 

There are other forms of communicating where connection is not neccessary, notable one is UDP ( User Datagram Protocol).

So how does it work?

We create two entities ( I mean two program for Server and Client)!

Server:           Client:
                        
Bind()            
socket()          socket()
Listen()          
Accept()          connect()
Read()            write()
Write()           read()
Close()           close()

These are some of the important steps for the communication. We can compare the module with a telephone. 

Server starts the phone and give it's number to the clients. Clients know the number ( portno, ip address) and then calls the server with a request, then the server accepts the request and then communication take place. Finally they close the socket. And the this is my friend is Socket Programming.


