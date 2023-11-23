// File Line: 59
// RVA: 0xEE3E94
void __fastcall OSuite::ZError::~ZError(OSuite::ZError *this)
{
  OSuite::ZString *p_m_Second; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *m_pLists; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZError::`vftable;
  p_m_Second = &this->m_noError.m_Second;
  p_m_Second[-1].OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
  OSuite::ZString::~ZString(p_m_Second);
  OSuite::ZMutex::~ZMutex(&this->m_mutex);
  this->m_enumerator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  this->m_enumerator.m_iterator.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  this->m_enumerator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  m_pList = this->m_enumerator.m_iterator.m_iterator.m_parents.m_pList;
  this->m_enumerator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_enumerator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  m_pLists = this->m_threadsErrorMap.m_pLists;
  this->m_threadsErrorMap.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
}

