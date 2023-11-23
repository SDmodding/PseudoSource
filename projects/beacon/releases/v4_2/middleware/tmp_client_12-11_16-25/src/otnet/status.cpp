// File Line: 11
// RVA: 0xEC3BD4
void __fastcall OSuite::OSError::OSError(
        OSuite::OSError *this,
        int thatErrorId,
        const char *thatErrorMessage,
        const char *thatErrorDetails)
{
  size_t v7; // rax
  size_t v8; // rax
  size_t v9; // rax
  size_t v10; // rax

  this->errorId = thatErrorId;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::OSError::`vftable;
  if ( thatErrorMessage )
  {
    v7 = strlen(thatErrorMessage);
    this->pErrorMessage = (char *)OSuite::ZObject::malloc(this, v7 + 1, 0i64);
    v8 = strlen(thatErrorMessage);
    strncpy(this->pErrorMessage, thatErrorMessage, v8 + 1);
  }
  if ( thatErrorDetails )
  {
    v9 = strlen(thatErrorDetails);
    this->pErrorDetails = (char *)OSuite::ZObject::malloc(this, v9 + 1, 0i64);
    v10 = strlen(thatErrorDetails);
    strncpy(this->pErrorDetails, thatErrorDetails, v10 + 1);
  }
}

// File Line: 36
// RVA: 0xEC3CF4
void __fastcall OSuite::OSError::~OSError(OSuite::OSError *this)
{
  char *pErrorMessage; // rdx

  pErrorMessage = this->pErrorMessage;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::OSError::`vftable;
  OSuite::ZObject::free(this, pErrorMessage);
  OSuite::ZObject::free(this, this->pErrorDetails);
}

// File Line: 47
// RVA: 0xEC3E28
OSuite::OSError *__fastcall OSuite::OSError::operator=(OSuite::OSError *this, OSuite::OSError *that)
{
  char *pErrorMessage; // rcx
  size_t v5; // rax
  size_t v6; // rax
  char *pErrorDetails; // rcx
  size_t v8; // rax
  size_t v9; // rax

  OSuite::ZObject::free(this, this->pErrorMessage);
  OSuite::ZObject::free(this, this->pErrorDetails);
  this->errorId = that->errorId;
  pErrorMessage = that->pErrorMessage;
  if ( pErrorMessage )
  {
    v5 = strlen(pErrorMessage);
    this->pErrorMessage = (char *)OSuite::ZObject::malloc(this, v5 + 1, 0i64);
    v6 = strlen(that->pErrorMessage);
    strncpy(this->pErrorMessage, that->pErrorMessage, v6 + 1);
  }
  pErrorDetails = that->pErrorDetails;
  if ( pErrorDetails )
  {
    v8 = strlen(pErrorDetails);
    this->pErrorDetails = (char *)OSuite::ZObject::malloc(this, v8 + 1, 0i64);
    v9 = strlen(that->pErrorDetails);
    strncpy(this->pErrorDetails, that->pErrorDetails, v9 + 1);
  }
  return this;
}

// File Line: 76
// RVA: 0xEC3C7C
void __fastcall OSuite::SCallbackData::SCallbackData(OSuite::SCallbackData *this)
{
  OSuite::ZObject *v2; // rdx
  OSuite::OSError *v3; // rax

  this->Status.nHttpStatus = -1;
  this->Status.eError = HTTPERROR_OK;
  this->eEvent = EVENT_NONE;
  OSuite::ZUrl::ZUrl(&this->URL);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->OSErrors, v2);
  this->OSErrors.m_pList = 0i64;
  this->OSErrors.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::ZListBase};
  this->OSErrors.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::IHashable};
  v3 = OSuite::TList<OSuite::OSError>::AllocList(&this->OSErrors, 0i64, 0x10ui64);
  this->OSErrors.m_nTop = 0i64;
  this->OSErrors.m_nSize = 16i64;
  this->OSErrors.m_pList = v3;
}

// File Line: 86
// RVA: 0xEC3D24
void __fastcall OSuite::SCallbackData::~SCallbackData(OSuite::SCallbackData *this)
{
  OSuite::OSError *m_pList; // rcx

  OSuite::SCallbackData::Clear(this);
  m_pList = this->OSErrors.m_pList;
  this->OSErrors.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::ZListBase};
  this->OSErrors.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::OSError>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
  {
    if ( LODWORD(m_pList[-1].pErrorDetails) )
      m_pList->vfptr->__vecDelDtor(m_pList, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pList[-1].pErrorDetails);
  }
  OSuite::ZUrl::~ZUrl(&this->URL);
}

// File Line: 91
// RVA: 0xEC4010
void __fastcall OSuite::SCallbackData::Clear(OSuite::SCallbackData *this)
{
  OSuite::TList<OSuite::OSError> *p_OSErrors; // rbx
  OSuite::OSError *m_pList; // rcx
  OSuite::OSError *v3; // rax

  p_OSErrors = &this->OSErrors;
  m_pList = this->OSErrors.m_pList;
  if ( m_pList )
  {
    if ( LODWORD(m_pList[-1].pErrorDetails) )
      m_pList->vfptr->__vecDelDtor(m_pList, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pList[-1].pErrorDetails);
  }
  v3 = OSuite::TList<OSuite::OSError>::AllocList(p_OSErrors, p_OSErrors->m_pList, 0x10ui64);
  p_OSErrors->m_nTop = 0i64;
  p_OSErrors->m_nSize = 16i64;
  p_OSErrors->m_pList = v3;
}

// File Line: 96
// RVA: 0xEC3ED8
OSuite::SCallbackData *__fastcall OSuite::SCallbackData::operator=(
        OSuite::SCallbackData *this,
        OSuite::SCallbackData *that)
{
  OSuite::ZUrl *p_URL; // rcx

  if ( this != that )
  {
    p_URL = &this->URL;
    p_URL[-1].m_nPort = that->eEvent;
    OSuite::ZUrl::operator=(p_URL, &that->URL);
    this->Status = that->Status;
    OSuite::TList<OSuite::OSError>::operator=(&this->OSErrors, &that->OSErrors);
  }
  return this;
}

