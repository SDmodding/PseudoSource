// File Line: 64
// RVA: 0x609DE0
void __fastcall UFG::UIHKStatItem::SetString(UFG::UIHKStatItem *this, UFG::qString *value)
{
  UFG::UIHKStatItem *v2; // rbx

  v2 = this;
  UFG::qString::Set(&this->mStringVal, value->mData, value->mLength, 0i64, 0);
  v2->mValue.mStatValueStr = v2->mStringVal.mData;
}

