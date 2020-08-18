#include <string>
#include <tchar.h>



const TCHAR* stringToTCHAR(const std::string& str) {
TCHAR wc[1000];
	
#ifdef UNICODE
	_stprintf_s(wc, 1000, _T("%S"), str.c_str());
#else
	_stprintf_s(wc, 1000, _T("%s"), str.c_str());
#endif
	return wc;
}