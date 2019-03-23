import socket
import sys
import getopt
import threading
import subprocess

listen  =   False   
command =   False
upload  =   False
execure =   ""
target  =   ""
upload_destination  =   ""
port    =   0

def usage():
    print ("BHP Net Tool")
    print
    print ("Usage: bhpnet.py -t target_host -p port")
    print ("-l --listen - listen on [host]:[port] for incoming connections")
    print ("-e --execute=file_to_run - execute the given file upon receiving a connection")
    print ("-c --command - initialize a command shell")
    print ("-u --upload=destination - upon receiving connection upload a file and write to [destination]")
    print
    print
    print ("Examples: ")
    print ("bhpnet.py -t 192.168.0.1 -p 5555 -l -c")
    print ("bhpnet.py -t 192.168.0.1 -p 5555 -l -u=c:\\target.exe")
    print ("bhpnet.py -t 192.168.0.1 -p 5555 -l -e=\"cat /etc/passwd\"")
    print ("echo 'ABCDEFGHI' | ./bhpnet.py -t 192.168.11.12 -p 135")
    sys.exit(0)

def main():
    global listen
    global target
    global command
    global port
    global execute
    global upload_destination

    if not len(sys.argv[1:]):
        usage()

    
    
