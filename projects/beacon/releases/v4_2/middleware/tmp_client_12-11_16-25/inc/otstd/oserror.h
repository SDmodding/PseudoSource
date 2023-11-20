// File Line: 59
// RVA: 0xEE3E94
void __fastcall OSuite::ZError::~ZError(OSuite::ZError *this)
{
  OSuite::ZError *v1; // rbx
  OSuite::ZString *v2; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rcx
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *v4; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZError::`vftable;
  v2 = &this->m_noError.m_Second;
  v2[-1].vfptr = (OSuite::IHashableVtbl *)&OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
  OSuite::ZString::~ZString(v2);
  OSuite::ZMutex::~ZMutex(&v1->m_mutex);
  v1->m_enumerator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  v1->m_enumerator.m_iterator.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v1->m_enumerator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v3 = v1->m_enumerator.m_iterator.m_iterator.m_parents.m_pList;
  v1->m_enumerator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v1->m_enumerator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
  v4 = v1->m_threadsErrorMap.m_pLists;
  v1->m_threadsErrorMap.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( v4 )
  {
    if ( LODWORD(v4[-1].m_Comparer.vfptr) )
      v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v4[-1].m_Comparer.vfptr);
  }
}

