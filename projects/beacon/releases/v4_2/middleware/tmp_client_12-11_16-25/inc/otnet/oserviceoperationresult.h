// File Line: 46
// RVA: 0xECDD98
void __fastcall OSuite::ZServiceOperationValue::ZServiceOperationValue(OSuite::ZServiceOperationValue *this)
{
  OSuite::ZServiceOperationValue *v1; // rdi
  OSuite::ZObject *v2; // rdx
  OSuite::ZServiceOperationValue **v3; // rax

  v1 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZServiceOperationValue::`vftable;
  OSuite::ZString::ZString(&v1->m_Name);
  OSuite::ZString::ZString(&v1->m_Value);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v1->m_subValues.vfptr, v2);
  v1->m_subValues.m_pList = 0i64;
  v1->m_subValues.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::ZListBase};
  v1->m_subValues.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::IHashable};
  v3 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(
                                            (OSuite::ZObject *)&v1->m_subValues.vfptr,
                                            0x80ui64,
                                            0i64);
  v1->m_subValues.m_nTop = 0i64;
  v1->m_subValues.m_nSize = 16i64;
  v1->m_subValues.m_pList = v3;
}

