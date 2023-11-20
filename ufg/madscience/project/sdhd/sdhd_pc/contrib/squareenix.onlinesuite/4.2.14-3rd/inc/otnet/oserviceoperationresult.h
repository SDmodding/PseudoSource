// File Line: 78
// RVA: 0x435740
OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *__fastcall OSuite::ZOServiceOperationResult::Values(OSuite::ZOServiceOperationResult *this, OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *result)
{
  OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *v2; // rbx

  v2 = result;
  OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(&this->m_Values, result);
  return v2;
}

