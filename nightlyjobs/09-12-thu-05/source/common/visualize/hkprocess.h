// File Line: 66
// RVA: 0xC3F820
void __fastcall hkProcess::getConsumableCommands(hkProcess *this, char **commands, int *numCommands)
{
  *commands = 0i64;
  *numCommands = 0;
}

// File Line: 74
// RVA: 0xC3F840
bool __fastcall hkProcess::isOk(hkProcess *this)
{
  hkDisplaySerializeOStream *m_outStream; // rcx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  m_outStream = this->m_outStream;
  return m_outStream && hkOArchive::isOk(m_outStream, &result)->m_bool;
}

