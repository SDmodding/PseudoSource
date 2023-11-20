// File Line: 108
// RVA: 0x3A0A90
void __fastcall PoseRecipeVisitor::AddAnim(PoseRecipeVisitor *this, PoseRecipe::AnimData *anim, hkaAnimation *animation)
{
  PoseRecipeVisitor *v3; // rdi
  unsigned int v4; // ebx
  __int64 v5; // rax

  v3 = this;
  if ( this->mStackCount < 0xC0 || this->mAnimDataCount < 0x62 )
  {
    v4 = this->mAnimDataCount;
    this->mAnimData[this->mAnimDataCount] = *anim;
    this->mAnimList[this->mAnimDataCount] = animation;
    v5 = this->mStackCount;
    ++this->mAnimDataCount;
    UFG::qMemSet(&this->mPoseStack[v5], 0, 0x10u);
    v3->mPoseStack[v3->mStackCount].mType = 2;
    *((_DWORD *)&v3->vfptr + 4 * (v3->mStackCount++ + 3i64)) = v4;
  }
  else
  {
    this->mIsValid = 0;
  }
}

