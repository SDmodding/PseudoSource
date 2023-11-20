// File Line: 29
// RVA: 0x5C4790
void __fastcall UFG::UIHKPlayerObjectiveMinimapBlip::UIHKPlayerObjectiveMinimapBlip(UFG::UIHKPlayerObjectiveMinimapBlip *this)
{
  UFG::UIHKPlayerObjectiveMinimapBlip *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->name.mUID = -1;
  UFG::qString::qString(&this->type);
  v2 = &v1->target;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->target.m_pPointer = 0i64;
}

