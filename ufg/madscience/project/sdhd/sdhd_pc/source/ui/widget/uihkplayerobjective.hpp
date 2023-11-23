// File Line: 29
// RVA: 0x5C4790
void __fastcall UFG::UIHKPlayerObjectiveMinimapBlip::UIHKPlayerObjectiveMinimapBlip(
        UFG::UIHKPlayerObjectiveMinimapBlip *this)
{
  this->name.mUID = -1;
  UFG::qString::qString(&this->type);
  this->target.mPrev = &this->target;
  this->target.mNext = &this->target;
  this->target.m_pPointer = 0i64;
}

