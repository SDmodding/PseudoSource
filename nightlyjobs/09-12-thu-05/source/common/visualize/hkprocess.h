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
  hkDisplaySerializeOStream *v1; // rcx
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this->m_outStream;
  return v1 && hkOArchive::isOk((hkOArchive *)&v1->vfptr, &result)->m_bool;
}

