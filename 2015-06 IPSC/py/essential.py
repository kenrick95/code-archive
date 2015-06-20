import sys
assert (2,7) <= sys.version_info < (3,0), 'Please use Python 2.7'

message = {}
message[1] = 'OK'
message[0] = 'All'
f = open('essential.txt','w')
f.write('{} {}\n'.format( message[0], message[1] ))
f.close()
