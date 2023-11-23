// File Line: 57
// RVA: 0x9BC20
void __fastcall UFG::CollisionEvent::~CollisionEvent(UFG::CollisionEvent *this)
{
  UFG::qNode<UFG::Event,UFG::Event> *mPrev; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *mNext; // rax

  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable;
  `eh vector destructor iterator(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
}

// File Line: 92
// RVA: 0x9BB50
void __fastcall UFG::BulletCollisionEvent::~BulletCollisionEvent(UFG::BulletCollisionEvent *this)
{
  UFG::qNode<UFG::Event,UFG::Event> *mPrev; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *mNext; // rax

  this->vfptr = (UFG::EventVtbl *)&UFG::BulletCollisionEvent::`vftable;
  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable;
  `eh vector destructor iterator(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
}

