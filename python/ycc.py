import sys
if len(sys.argv) < 4 :
	print ("Enter a few arguments (r g b) in 0...255")
	exit ()
for argument in sys.argv:
	print ("Arguments is {}".format(argument))

r,g,b =float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3])

y = int((0.299 * r) + (0.587 * g) + (0.114 * b))
cb = int(128 - (0.168736 * r) - (0.331264 * g) + (0.5 * b))
cr = int(128 + (0.5 * r) - (0.418688 * g) - (0.081312 * b))


print ("y = {}, cb = {}, cr = {}".format(y, cb, cr))
