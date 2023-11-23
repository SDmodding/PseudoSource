// File Line: 46
// RVA: 0xECDD98
void __fastcall OSuite::ZServiceOperationValue::ZServiceOperationValue(OSuite::ZServiceOperationValue *this)
{
  OSuite::ZObject *v2; // rdx
  OSuite::ZServiceOperationValue **v3; // rax

  OSuite::ZAtomBase::ZAtomBase(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZServiceOperationValue::`vftable;
  OSuite::ZString::ZString(&this->m_Name);
  OSuite::ZString::ZString(&this->m_Value);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_subValues, v2);
  this->m_subValues.m_pList = 0i64;
  this->m_subValues.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::ZListBase};
  this->m_subValues.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::`vftable{for `OSuite::IHashable};
  v3 = (OSuite::ZServiceOperationValue **)OSuite::ZObject::malloc(&this->m_subValues, 0x80ui64, 0i64);
  this->m_subValues.m_nTop = 0i64;
  this->m_subValues.m_nSize = 16i64;
  this->m_subValues.m_pList = v3;
}

