def copy_symbol_to_binary(elf_file,symbol,file):
		nm_process=Popen(['arm-none-eabi-nm','-S','--size-sort',elf_file],stdout=PIPE)
		output=nm_process.communicate()[0]
		if not output:
			raise InvalidBinaryError()
		output=[line.split()for line in output.splitlines()]
		for sym in output:
			if symbol==sym[-1]and len(sym)==4:
				start = int(sym[0],16)
				end = start + int(sym[1],16)

				s = ""
				nm_process=Popen(['arm-none-eabi-objdump','-d','-EB','--section=.text','--start-address='+str(start), "--stop-address=" + str(end), elf_file],stdout=PIPE)
				output=nm_process.communicate()[0]
				if not output:
					raise InvalidBinaryError()
				for line in output.splitlines():
					splitted = [splits for splits in line.split("\t") if splits is not ""]
					if len(splitted)>2:
						s += splitted[1].replace(" ", "")

				with open(file, "wb") as f:
					f.write(s.decode('hex'))
					
				return int(sym[0],16)
		raise Exception("Could not locate symbol <%s> in binary! Failed to copy symbol memory to binary file"%(symbol))