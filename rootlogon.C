#if ROOT_VERSION_CODE > ROOT_VERSION(6,0,0)
R__LOAD_LIBRARY(libPSD.dylib)
void rootlogon() {
}
#else
void rootlogon() {
	gSystem->Load("libPSD.dylib");
}
#endif

