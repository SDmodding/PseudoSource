// File Line: 167
// RVA: 0x5E9590
UFG::qString *__fastcall UFG::StoreFront::GetStoreTitle(UFG::StoreFront *this, UFG::qString *result)
{
  UFG::qString::qString(result, &this->mStoreTitle);
  return result;
}

// File Line: 168
// RVA: 0x5E9550
UFG::qString *__fastcall UFG::StoreFront::GetStoreDesc(UFG::StoreFront *this, UFG::qString *result)
{
  UFG::qString::qString(result, &this->mStoreDesc);
  return result;
}

