// File Line: 35
// RVA: 0xA392B0
void __fastcall UFG::DiskCache::SetCallback(void (__fastcall *callback)(const char *, bool, void *), void *callback_data)
{
  UFG::DiskCache::m_Callback = callback;
  UFG::DiskCache::m_CallbackData = callback_data;
}

