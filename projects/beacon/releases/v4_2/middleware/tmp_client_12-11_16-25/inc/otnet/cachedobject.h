// File Line: 67
// RVA: 0xECBFD0
void __fastcall OSuite::TAtomObject<OSuite::ZOFeed>::Read(
        OSuite::TAtomObject<OSuite::ZOFeed> *this,
        OSuite::IReader *pReader)
{
  OSuite::ZOFeed *v4; // rcx

  v4 = (OSuite::ZOFeed *)OSuite::ZObject::operator new(0x1B0ui64);
  if ( v4 )
  {
    v4->m_sAuthorName.m_pString = 0i64;
    v4->m_sIdentifier.m_pString = 0i64;
    v4->m_sTitle.m_pString = 0i64;
    v4->m_sEditURL.m_pString = 0i64;
    v4->m_sBaseURL.m_pString = 0i64;
    v4->m_sSubTitle.m_pString = 0i64;
    v4->m_sFeedURL.m_sProtocol.m_pString = 0i64;
    v4->m_sFeedURL.m_sHost.m_pString = 0i64;
    v4->m_sFeedURL.m_sFakeHost.m_pString = 0i64;
    v4->m_sFeedURL.m_sPath.m_pString = 0i64;
    v4->m_sFeedURL.m_urlParameters.m_parameters.m_pTop = 0i64;
    v4->m_sFeedURL.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
    v4->m_Entries.m_pList = 0i64;
    v4->m_pEdmEntityType = 0i64;
    OSuite::ZOFeed::ZOFeed(v4, pReader, &this->m_cbData.URL);
  }
}

