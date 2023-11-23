// File Line: 64
// RVA: 0x609DE0
void __fastcall UFG::UIHKStatItem::SetString(UFG::UIHKStatItem *this, UFG::qString *value)
{
  UFG::qString::Set(&this->mStringVal, value->mData, value->mLength, 0i64, 0);
  this->mValue.mStatValueStr = this->mStringVal.mData;
}

