from struct import *


def openFile (filename):
	with open(filename, 'rb') as file :
		header = getHeader(file)
		file.seek(header[4], 0)
		sizeIFDTags = getSizeIFDTags(file)
		IFDTags = getIFDTags(file, sizeIFDTags)
		#IFDTags 4-width 10-height
		nextIFDOffset = getNextIFDOffset(file)
		print(IFDTags)
		

def getHeader (file):
	formatStruct = '>4BI'
	sizeStruct = calcsize(formatStruct) 
	return unpack(formatStruct, file.read(sizeStruct))

def getSizeIFDTags (file):
	formatStruct = '>H'
	sizeStruct = calcsize(formatStruct)
	return unpack(formatStruct, file.read(sizeStruct))[0]

def getIFDTags (file, countTags):
	formatStruct = '>'+str(countTags)+'H'
	sizeStruct = calcsize(formatStruct)
	return unpack(formatStruct, file.read(sizeStruct))

def getNextIFDOffset (file):
	formatStruct = '>I'
	sizeStruct = calcsize(formatStruct)
	return unpack(formatStruct, file.read(sizeStruct))[0]

def getImageBody (file, width, height, countChannel = 3)
	sizeImg = width * height * countChannel
	formatStruct = '>'+str(sizeImg)+'B'
	sizeStruct = calcsize(formatStruct)
	return unpack(formatStruct, file.read(sizeStruct))
