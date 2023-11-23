// File Line: 78
// RVA: 0x435740
OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *__fastcall OSuite::ZOServiceOperationResult::Values(
        OSuite::ZOServiceOperationResult *this,
        OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> *result)
{
  OSuite::TList<OSuite::ZServiceOperationValue *>::Iterator(&this->m_Values, result);
  return result;
}

