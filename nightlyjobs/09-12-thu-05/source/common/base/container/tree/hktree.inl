// File Line: 33
// RVA: 0xE689A0
hkTree<hkRefPtr<hkXmlParser::Node> >::Node *__fastcall hkTree<hkRefPtr<hkXmlParser::Node>>::appendChild(
        hkTree<hkRefPtr<hkXmlParser::Node> > *this,
        hkTree<hkRefPtr<hkXmlParser::Node> >::Node *iter,
        hkRefPtr<hkXmlParser::Node> *value)
{
  _QWORD **v6; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v7; // rbx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *m_firstChild; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *i; // rcx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *m_root; // rcx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *j; // rax

  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkTree<hkRefPtr<hkXmlParser::Node> >::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v6[11] + 8i64))(
                                                       v6[11],
                                                       32i64);
  if ( v7 )
  {
    v7->m_firstChild = 0i64;
    v7->m_nextSibling = 0i64;
    v7->m_parent = 0i64;
    if ( value->m_pntr )
      hkReferencedObject::addReference(value->m_pntr);
    v7->m_value = (hkRefPtr<hkXmlParser::Node>)value->m_pntr;
  }
  else
  {
    v7 = 0i64;
  }
  v7->m_parent = iter;
  if ( iter )
  {
    m_firstChild = iter->m_firstChild;
    if ( iter->m_firstChild )
    {
      for ( i = m_firstChild->m_nextSibling; i; i = i->m_nextSibling )
        m_firstChild = i;
      m_firstChild->m_nextSibling = v7;
    }
    else
    {
      iter->m_firstChild = v7;
    }
  }
  else
  {
    m_root = this->m_root;
    if ( this->m_root )
    {
      for ( j = m_root->m_nextSibling; j; j = j->m_nextSibling )
        m_root = j;
      m_root->m_nextSibling = v7;
    }
    else
    {
      this->m_root = v7;
    }
  }
  return v7;
}

// File Line: 82
// RVA: 0xE68A80
void __fastcall hkTree<hkRefPtr<hkXmlParser::Node>>::remove(
        hkTree<hkRefPtr<hkXmlParser::Node> > *this,
        hkTree<hkRefPtr<hkXmlParser::Node> >::Node *iter)
{
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *m_parent; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v3; // rbx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *m_firstChild; // rcx
  __int64 p_m_nextSibling; // rax
  bool v6; // zf
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *i; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *m_nextSibling; // rdi
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v9; // rax
  hkReferencedObject *m_pntr; // rcx
  _QWORD **Value; // rax

  m_parent = iter->m_parent;
  v3 = iter;
  if ( m_parent )
  {
    m_firstChild = m_parent->m_firstChild;
    if ( m_parent->m_firstChild == iter )
    {
      m_parent->m_firstChild = 0i64;
    }
    else
    {
      p_m_nextSibling = (__int64)&m_firstChild->m_nextSibling;
      if ( m_firstChild->m_nextSibling != iter )
      {
        do
        {
          m_firstChild = *(hkTree<hkRefPtr<hkXmlParser::Node> >::Node **)p_m_nextSibling;
          v6 = *(_QWORD *)(*(_QWORD *)p_m_nextSibling + 8i64) == (_QWORD)iter;
          p_m_nextSibling = *(_QWORD *)p_m_nextSibling + 8i64;
        }
        while ( !v6 );
      }
      m_firstChild->m_nextSibling = iter->m_nextSibling;
    }
    iter->m_parent = 0i64;
  }
  do
  {
    for ( i = v3->m_firstChild; i; i = i->m_firstChild )
      v3 = i;
    m_nextSibling = v3->m_nextSibling;
    if ( !m_nextSibling )
      m_nextSibling = v3->m_parent;
    v9 = v3->m_parent;
    if ( v9 )
      v9->m_firstChild = 0i64;
    m_pntr = v3->m_value.m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    v3->m_value.m_pntr = 0i64;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkTree<hkRefPtr<hkXmlParser::Node> >::Node *, __int64))(*Value[11] + 16i64))(
      Value[11],
      v3,
      32i64);
    v3 = m_nextSibling;
  }
  while ( m_nextSibling );
}

