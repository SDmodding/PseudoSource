// File Line: 11
// RVA: 0xEC3BD4
void __fastcall OSuite::OSError::OSError(OSuite::OSError *this, int thatErrorId, const char *thatErrorMessage, const char *thatErrorDetails)
{
  const char *v4; // rdi
  const char *v5; // rsi
  OSuite::OSError *v6; // rbx
  size_t v7; // rax
  size_t v8; // rax
  size_t v9; // rax
  size_t v10; // rax

  v4 = thatErrorDetails;
  v5 = thatErrorMessage;
  v6 = this;
  this->errorId = thatErrorId;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::OSError::`vftable';
  if ( thatErrorMessage )
  {
    v7 = strlen(thatErrorMessage);
    v6->pErrorMessage = (char *)OSuite::ZObject::malloc((OSuite::ZObject *)&v6->vfptr, v7 + 1, 0i64);
    v8 = strlen(v5);
    strncpy(v6->pErrorMessage, v5, v8 + 1);
  }
  if ( v4 )
  {
    v9 = strlen(v4);
    v6->pErrorDetails = (char *)OSuite::ZObject::malloc((OSuite::ZObject *)&v6->vfptr, v9 + 1, 0i64);
    v10 = strlen(v4);
    strncpy(v6->pErrorDetails, v4, v10 + 1);
  }
}

// File Line: 36
// RVA: 0xEC3CF4
void __fastcall OSuite::OSError::~OSError(OSuite::OSError *this)
{
  char *v1; // rdx
  OSuite::OSError *v2; // rbx

  v1 = this->pErrorMessage;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::OSError::`vftable';
  OSuite::ZObject::free((OSuite::ZObject *)&this->vfptr, v1);
  OSuite::ZObject::free((OSuite::ZObject *)&v2->vfptr, v2->pErrorDetails);
}

// File Line: 47
// RVA: 0xEC3E28
OSuite::OSError *__fastcall OSuite::OSError::operator=(OSuite::OSError *this, OSuite::OSError *that)
{
  OSuite::OSError *v2; // rdi
  OSuite::OSError *v3; // rbx
  const char *v4; // rcx
  size_t v5; // rax
  size_t v6; // rax
  const char *v7; // rcx
  size_t v8; // rax
  size_t v9; // rax

  v2 = that;
  v3 = this;
  OSuite::ZObject::free((OSuite::ZObject *)&this->vfptr, this->pErrorMessage);
  OSuite::ZObject::free((OSuite::ZObject *)&v3->vfptr, v3->pErrorDetails);
  v3->errorId = v2->errorId;
  v4 = v2->pErrorMessage;
  if ( v4 )
  {
    v5 = strlen(v4);
    v3->pErrorMessage = (char *)OSuite::ZObject::malloc((OSuite::ZObject *)&v3->vfptr, v5 + 1, 0i64);
    v6 = strlen(v2->pErrorMessage);
    strncpy(v3->pErrorMessage, v2->pErrorMessage, v6 + 1);
  }
  v7 = v2->pErrorDetails;
  if ( v7 )
  {
    v8 = strlen(v7);
    v3->pErrorDetails = (char *)OSuite::ZObject::malloc((OSuite::ZObject *)&v3->vfptr, v8 + 1, 0i64);
    v9 = strlen(v2->pErrorDetails);
    strncpy(v3->pErrorDetails, v2->pErrorDetails, v9 + 1);
  }
  return v3;
}

// File Line: 76
// RVA: 0xEC3C7C
void __fastcall OSuite::SCallbackData::SCallbackData(OSuite::SCallbackData *this)
{
  OSuite::SCallbackData *v1; // rdi
  OSuite::ZObject *v2; // rdx
  OSuite::OSError *v3; // rax

  this->Status.nHttpStatus = -1;
  this->Status.eError = 0;
  this->eEvent = 0;
  v1 = this;
  OSuite::ZUrl::ZUrl(&this->URL);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v1->OSErrors.vfptr, v2);
  v1->OSErrors.m_pList = 0i64;
  v1->OSErrors.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::ZListBase'};
  v1->OSErrors.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::IHashable'};
  v3 = OSuite::TList<OSuite::OSError>::AllocList(&v1->OSErrors, 0i64, 0x10ui64);
  v1->OSErrors.m_nTop = 0i64;
  v1->OSErrors.m_nSize = 16i64;
  v1->OSErrors.m_pList = v3;
}

// File Line: 86
// RVA: 0xEC3D24
void __fastcall OSuite::SCallbackData::~SCallbackData(OSuite::SCallbackData *this)
{
  OSuite::SCallbackData *v1; // rbx
  OSuite::OSError *v2; // rcx

  v1 = this;
  OSuite::SCallbackData::Clear(this);
  v2 = v1->OSErrors.m_pList;
  v1->OSErrors.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::ZListBase'};
  v1->OSErrors.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable'{for `OSuite::IHashable'};
  if ( v2 )
  {
    if ( LODWORD(v2[-1].pErrorDetails) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].pErrorDetails);
  }
  OSuite::ZUrl::~ZUrl(&v1->URL);
}

// File Line: 91
// RVA: 0xEC4010
void __fastcall OSuite::SCallbackData::Clear(OSuite::SCallbackData *this)
{
  OSuite::TList<OSuite::OSError> *v1; // rbx
  OSuite::OSError *v2; // rcx
  OSuite::OSError *v3; // rax

  v1 = &this->OSErrors;
  v2 = this->OSErrors.m_pList;
  if ( v2 )
  {
    if ( LODWORD(v2[-1].pErrorDetails) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].pErrorDetails);
  }
  v3 = OSuite::TList<OSuite::OSError>::AllocList(v1, (OSuite::ZObject *)&v1->m_pList->vfptr, 0x10ui64);
  v1->m_nTop = 0i64;
  v1->m_nSize = 16i64;
  v1->m_pList = v3;
}

// File Line: 96
// RVA: 0xEC3ED8
OSuite::SCallbackData *__fastcall OSuite::SCallbackData::operator=(OSuite::SCallbackData *this, OSuite::SCallbackData *that)
{
  OSuite::SCallbackData *v2; // rdi
  OSuite::SCallbackData *v3; // rbx
  OSuite::ZUrl *v4; // rcx

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    v4 = &this->URL;
    v4[-1].m_nPort = that->eEvent;
    OSuite::ZUrl::operator=(v4, &that->URL);
    v3->Status = v2->Status;
    OSuite::TList<OSuite::OSError>::operator=(&v3->OSErrors, &v2->OSErrors);
  }
  return v3;
}

