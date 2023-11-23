// File Line: 108
// RVA: 0x3A0A90
void __fastcall PoseRecipeVisitor::AddAnim(
        PoseRecipeVisitor *this,
        PoseRecipe::AnimData *anim,
        hkaAnimation *animation)
{
  unsigned int mAnimDataCount; // ebx
  __int64 mStackCount; // rax

  if ( this->mStackCount < 0xC0 || this->mAnimDataCount < 0x62 )
  {
    mAnimDataCount = this->mAnimDataCount;
    this->mAnimData[mAnimDataCount] = *anim;
    this->mAnimList[this->mAnimDataCount] = animation;
    mStackCount = this->mStackCount;
    ++this->mAnimDataCount;
    UFG::qMemSet(&this->mPoseStack[mStackCount], 0, 0x10u);
    this->mPoseStack[this->mStackCount].mType = PoseDescType_Anim;
    this->mPoseStack[this->mStackCount++].mAnim.mIndex = mAnimDataCount;
  }
  else
  {
    this->mIsValid = 0;
  }
}

