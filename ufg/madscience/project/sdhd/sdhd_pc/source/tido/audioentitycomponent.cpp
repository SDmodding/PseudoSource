// File Line: 24
// RVA: 0x59CE20
UFG::ComponentIDDesc *__fastcall UFG::HkAudioEntityComponent::GetDesc(UFG::HkAudioEntityComponent *this)
{
  return &UFG::HkAudioEntityComponent::_TypeIDesc;
}

// File Line: 28
// RVA: 0x593470
void __fastcall UFG::HkAudioEntityComponent::HkAudioEntityComponent(
        UFG::HkAudioEntityComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimComponent::SimComponent(this, pSceneObj->m_NameUID);
  UFG::AudioEntity::AudioEntity(&this->UFG::AudioEntity);
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::SimComponent};
  this->UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::AudioEntity};
  UFG::SimComponent::AddType(
    this,
    UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID,
    "HkAudioEntityComponent");
}

// File Line: 38
// RVA: 0x594710
void __fastcall UFG::HkAudioEntityComponent::~HkAudioEntityComponent(UFG::HkAudioEntityComponent *this)
{
  UFG::AudioEntity *v2; // rcx

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::SimComponent};
  v2 = &this->UFG::AudioEntity;
  v2->vfptr = (UFG::AudioEntityVtbl *)&UFG::HkAudioEntityComponent::`vftable{for `UFG::AudioEntity};
  UFG::AudioEntity::~AudioEntity(v2);
  UFG::SimComponent::~SimComponent(this);
}

