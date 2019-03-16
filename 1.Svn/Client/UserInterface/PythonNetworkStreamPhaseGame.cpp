//Find
	buf[whisperPacket.wSize - sizeof(whisperPacket)] = '\0';
	
///Add
#ifdef ENABLE_WHISPER_RENEWAL
	#include "PythonWhisper.h"
	if (CPythonChat::WHISPER_TYPE_NOT_EXIST != whisperPacket.bType) {
		if (std::string(buf).find("|?whisper_renewal>|") != std::string::npos) {
			CPythonWhisper::Instance().AddName(whisperPacket.szNameFrom, CPythonWhisper::TARGET);
			return true;
		}
		else if (std::string(buf).find("|?whisper_renewal<|") != std::string::npos) {
			CPythonWhisper::Instance().DeleteName(whisperPacket.szNameFrom, CPythonWhisper::TARGET);
			return true;
		}
	}
#endif	
