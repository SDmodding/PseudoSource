// File Line: 92
// RVA: 0x6D2780
void __fastcall Scaleform::GFx::Task::~Task(Scaleform::GFx::Task *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

// File Line: 158
// RVA: 0x6F6600
Scaleform::Ptr<Scaleform::GFx::TaskManager> *__fastcall Scaleform::GFx::StateBag::GetTaskManager(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::TaskManager> *result)
{
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::TaskManager *)this->vfptr->GetStateAddRef(
                                                     this,
                                                     (Scaleform::GFx::State::StateType)24i64);
  return v2;
}

