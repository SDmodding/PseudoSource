// File Line: 160
// RVA: 0xEC6A24
void __fastcall OSuite::ZAtomEntry::UploadRequest::UploadRequest(OSuite::ZAtomEntry::UploadRequest *this, OSuite::IReader *pAttachment, OSuite::SHttpStatus *externalStatus)
{
  OSuite::ZAtomEntry::UploadRequest *v3; // rsi
  OSuite::SHttpStatus *v4; // rbx
  OSuite::IReader *v5; // rdi

  v3 = this;
  v4 = externalStatus;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::Request::`vftable';
  v5 = pAttachment;
  OSuite::SCallbackData::SCallbackData(&this->m_CbData);
  v3->m_clientCallback.m_Closure.m_pthis = 0i64;
  v3->m_clientCallback.m_Closure.m_pFunction = 0i64;
  v3->m_externalStatus = v4;
  v3->m_pAttachment = v5;
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::UploadRequest::`vftable';
  OSuite::ZStringBuilder::ZStringBuilder((OSuite::ZStringBuilder *)&v3->m_entrycontent, 0x400ui64);
  v3->m_readerOwnership = 1;
}

