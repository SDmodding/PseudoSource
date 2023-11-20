// File Line: 24
// RVA: 0x59CE20
UFG::ComponentIDDesc *__fastcall UFG::HkAudioEntityComponent::GetDesc(UFG::HkAudioEntityComponent *this)
{
  return &UFG::HkAudioEntityComponent::_TypeIDesc;
}

// File Line: 28
// RVA: 0x593470
void __fastcall UFG::HkAudioEntityComponent::HkAudioEntityComponent(UFG::HkAudioEntityComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::HkAudioEntityComponent *v2; // rdi

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, pSceneObj->m_NameUID);
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&v2->vfptr);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::AudioEntity};
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID,
    "HkAudioEntityComponent");
}

// File Line: 38
// RVA: 0x594710
void __fastcall UFG::HkAudioEntityComponent::~HkAudioEntityComponent(UFG::HkAudioEntityComponent *this)
{
  UFG::HkAudioEntityComponent *v1; // rbx
  UFG::AudioEntity *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::SimComponent};
  v2 = (UFG::AudioEntity *)&this->vfptr;
  v2->vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::AudioEntity};
  UFG::AudioEntity::~AudioEntity(v2);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

