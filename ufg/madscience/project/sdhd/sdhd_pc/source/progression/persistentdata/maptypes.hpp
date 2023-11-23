// File Line: 24
// RVA: 0x48CE00
void __fastcall UFG::PersistentData::KeyValue::KeyValue(UFG::PersistentData::KeyValue *this)
{
  this->mKey = UFG::gNullQSymbol;
  this->mIntValue = 0;
}

// File Line: 41
// RVA: 0x48CDE0
void __fastcall UFG::PersistentData::KeyValue64::KeyValue64(UFG::PersistentData::KeyValue64 *this)
{
  this->mKey = UFG::gNullQSymbol;
  this->mIntValue = 0i64;
}

// File Line: 51
// RVA: 0x48CDC0
void __fastcall UFG::PersistentData::KeyBinary::KeyBinary(UFG::PersistentData::KeyBinary *this)
{
  this->mKey = UFG::gNullQSymbol;
  this->mBinary.mpBuffer = 0i64;
  this->mBinary.mSize = 0;
}

// File Line: 293
// RVA: 0x42C720
UFG::PersistentData::MapFloat::Iterator *__fastcall UFG::PersistentData::MapInt::GetIterator(
        UFG::PersistentData::MapFloat *this,
        UFG::PersistentData::MapFloat::Iterator *result)
{
  result->mIndex = 0;
  result->mList = this;
  return result;
}

