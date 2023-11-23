// File Line: 160
// RVA: 0xEC6A24
void __fastcall OSuite::ZAtomEntry::UploadRequest::UploadRequest(
        OSuite::ZAtomEntry::UploadRequest *this,
        OSuite::IReader *pAttachment,
        OSuite::SHttpStatus *externalStatus)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::Request::`vftable;
  OSuite::SCallbackData::SCallbackData(&this->m_CbData);
  this->m_clientCallback.m_Closure.m_pthis = 0i64;
  this->m_clientCallback.m_Closure.m_pFunction = 0i64;
  this->m_externalStatus = externalStatus;
  this->m_pAttachment = pAttachment;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::UploadRequest::`vftable;
  OSuite::ZStringBuilder::ZStringBuilder((OSuite::ZStringBuilder *)&this->m_entrycontent, 0x400ui64);
  this->m_readerOwnership = 1;
}

