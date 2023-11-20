// File Line: 50
// RVA: 0xE778B0
signed __int64 __fastcall hkServerProcessHandler::getProcessId(hkServerProcessHandler *this, const char *name)
{
  return hkProcessFactory::getProcessId(hkSingleton<hkProcessFactory>::s_instance, name);
}

// File Line: 51
// RVA: 0xE778C0
const char *__fastcall hkServerProcessHandler::getProcessName(hkServerProcessHandler *this, int tag)
{
  return hkProcessFactory::getProcessName(hkSingleton<hkProcessFactory>::s_instance, tag);
}

// File Line: 59
// RVA: 0xE778D0
__int64 __fastcall hkServerProcessHandler::getProcessTag(hkServerProcessHandler *this)
{
  return (unsigned int)hkServerProcessHandler::m_tag;
}

