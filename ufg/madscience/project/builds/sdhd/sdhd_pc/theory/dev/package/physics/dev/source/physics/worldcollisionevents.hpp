// File Line: 57
// RVA: 0x9BC20
void __fastcall UFG::CollisionEvent::~CollisionEvent(UFG::CollisionEvent *this)
{
  UFG::CollisionEvent *v1; // rbx
  UFG::qNode<UFG::Event,UFG::Event> *v2; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *v3; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v4; // rax

  v1 = this;
  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable;
  `eh vector destructor iterator(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v1->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  v2 = (UFG::qNode<UFG::Event,UFG::Event> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
}

// File Line: 92
// RVA: 0x9BB50
void __fastcall UFG::BulletCollisionEvent::~BulletCollisionEvent(UFG::BulletCollisionEvent *this)
{
  UFG::BulletCollisionEvent *v1; // rbx
  UFG::qNode<UFG::Event,UFG::Event> *v2; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *v3; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v4; // rax

  v1 = this;
  this->vfptr = (UFG::EventVtbl *)&UFG::BulletCollisionEvent::`vftable;
  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable;
  `eh vector destructor iterator(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v1->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  v2 = (UFG::qNode<UFG::Event,UFG::Event> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
}

