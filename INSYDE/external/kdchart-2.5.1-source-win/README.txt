THIS DIRECTORY

This directory contains external KDChart Libraries. Before compile the INSYDE source code you should 
put KDChart Libraries in the right folder as follows:

-lib
	-x64			<- 64 bits Libraries
		-vc12		<- Put your libraries compiled with VC2013
		-vc14		<- Put your libraries compiled with VC2015
	-x86			<- 32 bits Libraries
		-mingw		<- Put your libraries compiled with MINGW
		-vc12		<- Put your libraries compiled with VC2013
		-vc14		<- Put your libraries compiled with VC2015

To differenciate between debug and release versions you should name each file as follow: kdchart2 for release 
and kdchard2 for debug (notice the extra "d" character) followed by the extension (.dll, .lib, etc). 