// File Line: 22
// RVA: 0xC656E0
void __fastcall hkOptionalComponent::hkOptionalComponent(
        hkOptionalComponent *this,
        const char *name,
        void (__fastcall *onLink)())
{
  hkOptionalComponent *v3; // rax

  v3 = s_components;
  this->m_name = name;
  this->m_onLink = onLink;
  this->m_next = v3;
  s_components = this;
  this->m_funcPtr = 0i64;
  this->m_func = 0i64;
  *(_WORD *)&this->m_isUsed.m_bool = 0;
}

// File Line: 34
// RVA: 0xC656A0
void __fastcall hkOptionalComponent::hkOptionalComponent(
        hkOptionalComponent *this,
        const char *name,
        void **funcPtr,
        void *func)
{
  hkOptionalComponent *v4; // rax

  v4 = s_components;
  this->m_name = name;
  this->m_onLink = 0i64;
  this->m_next = v4;
  this->m_funcPtr = funcPtr;
  this->m_func = func;
  *(_WORD *)&this->m_isUsed.m_bool = 0;
  s_components = this;
}

// File Line: 39
// RVA: 0xC65720
hkOptionalComponent *__fastcall hkOptionalComponent::getFirstComponent()
{
  return s_components;
}

// File Line: 44
// RVA: 0xC65810
void __fastcall hkOptionalComponent::request(hkOptionalComponent *this)
{
  void (*m_onLink)(void); // rax
  void **m_funcPtr; // rcx

  this->m_isRequested.m_bool = 1;
  m_onLink = this->m_onLink;
  if ( m_onLink )
    m_onLink();
  m_funcPtr = this->m_funcPtr;
  if ( m_funcPtr )
    *m_funcPtr = this->m_func;
}

// File Line: 62
// RVA: 0xC65730
void __fastcall hkOptionalComponent::writeReport(hkOstream *os)
{
  int v2; // ebp
  const char **v3; // r14
  char v4; // si
  hkOptionalComponent *i; // rbx

  v2 = 0;
  v3 = header;
  do
  {
    v4 = 0;
    for ( i = hkOptionalComponent::getFirstComponent(); i; i = i->m_next )
    {
      if ( ((i->m_isRequested.m_bool != 0) | (2 * (i->m_isUsed.m_bool != 0))) == v2 )
      {
        if ( !v4 )
        {
          v4 = 1;
          hkOstream::printf(os, "\n\n========================================================\n");
          hkOstream::printf(os, "%s\n", *v3);
          hkOstream::printf(os, "--------------------------------------------------------\n");
        }
        hkOstream::printf(os, "%s\n", i->m_name);
      }
    }
    ++v3;
    ++v2;
  }
  while ( (__int64)v3 < (__int64)&hkThreadPool `RTTI Type Descriptor );
}

