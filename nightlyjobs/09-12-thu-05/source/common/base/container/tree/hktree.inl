// File Line: 33
// RVA: 0xE689A0
hkTree<hkRefPtr<hkXmlParser::Node> >::Node *__fastcall hkTree<hkRefPtr<hkXmlParser::Node>>::appendChild(hkTree<hkRefPtr<hkXmlParser::Node> > *this, hkTree<hkRefPtr<hkXmlParser::Node> >::Node *iter, hkRefPtr<hkXmlParser::Node> *value)
{
  hkTree<hkRefPtr<hkXmlParser::Node> > *v3; // rsi
  hkReferencedObject **v4; // r14
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v5; // rdi
  _QWORD **v6; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v7; // rbx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v8; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *i; // rcx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v10; // rcx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *j; // rax

  v3 = this;
  v4 = (hkReferencedObject **)value;
  v5 = iter;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkTree<hkRefPtr<hkXmlParser::Node> >::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(
                                                       v6[11],
                                                       32i64);
  if ( v7 )
  {
    v7->m_firstChild = 0i64;
    v7->m_nextSibling = 0i64;
    v7->m_parent = 0i64;
    if ( *v4 )
      hkReferencedObject::addReference(*v4);
    v7->m_value.m_pntr = (hkXmlParser::Node *)*v4;
  }
  else
  {
    v7 = 0i64;
  }
  v7->m_parent = v5;
  if ( v5 )
  {
    v8 = v5->m_firstChild;
    if ( v5->m_firstChild )
    {
      for ( i = v8->m_nextSibling; i; i = i->m_nextSibling )
        v8 = i;
      v8->m_nextSibling = v7;
    }
    else
    {
      v5->m_firstChild = v7;
    }
  }
  else
  {
    v10 = v3->m_root;
    if ( v3->m_root )
    {
      for ( j = v10->m_nextSibling; j; j = j->m_nextSibling )
        v10 = j;
      v10->m_nextSibling = v7;
    }
    else
    {
      v3->m_root = v7;
    }
  }
  return v7;
}

// File Line: 82
// RVA: 0xE68A80
void __fastcall hkTree<hkRefPtr<hkXmlParser::Node>>::remove(hkTree<hkRefPtr<hkXmlParser::Node> > *this, hkTree<hkRefPtr<hkXmlParser::Node> >::Node *iter)
{
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v2; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v3; // rbx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v4; // rcx
  signed __int64 v5; // rax
  bool v6; // zf
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v7; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v8; // rdi
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v9; // rax
  hkReferencedObject *v10; // rcx
  _QWORD **v11; // rax

  v2 = iter->m_parent;
  v3 = iter;
  if ( v2 )
  {
    v4 = v2->m_firstChild;
    if ( v2->m_firstChild == iter )
    {
      v2->m_firstChild = 0i64;
    }
    else
    {
      v5 = (signed __int64)&v4->m_nextSibling;
      if ( v4->m_nextSibling != iter )
      {
        do
        {
          v4 = *(hkTree<hkRefPtr<hkXmlParser::Node> >::Node **)v5;
          v6 = *(_QWORD *)(*(_QWORD *)v5 + 8i64) == (_QWORD)iter;
          v5 = *(_QWORD *)v5 + 8i64;
        }
        while ( !v6 );
      }
      v4->m_nextSibling = iter->m_nextSibling;
    }
    iter->m_parent = 0i64;
  }
  do
  {
    v7 = v3->m_firstChild;
    if ( v3->m_firstChild )
    {
      do
      {
        v3 = v7;
        v7 = v7->m_firstChild;
      }
      while ( v7 );
    }
    v8 = v3->m_nextSibling;
    if ( !v8 )
      v8 = v3->m_parent;
    v9 = v3->m_parent;
    if ( v9 )
      v9->m_firstChild = 0i64;
    v10 = (hkReferencedObject *)&v3->m_value.m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
    v3->m_value.m_pntr = 0i64;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkTree<hkRefPtr<hkXmlParser::Node> >::Node *, signed __int64))(*v11[11] + 16i64))(
      v11[11],
      v3,
      32i64);
    v3 = v8;
  }
  while ( v8 );
}

