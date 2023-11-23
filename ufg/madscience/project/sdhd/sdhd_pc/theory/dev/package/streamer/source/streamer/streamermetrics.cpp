// File Line: 722
// RVA: 0x22E2D0
void __fastcall UFG::StreamerMetrics::SetDBGFileOpReadCB(
        void (__fastcall *fileReadCB)(float, float, void *, const char *))
{
  UFG::gDBGFileOpRead = fileReadCB;
}

