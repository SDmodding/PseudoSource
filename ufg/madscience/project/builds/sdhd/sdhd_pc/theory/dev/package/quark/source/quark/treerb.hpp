// File Line: 173
// RVA: 0x66BF60
void __fastcall UFG::qTreeRB<UFG::EngineModelInput,UFG::EngineModelInput,1>::~qTreeRB<UFG::EngineModelInput,UFG::EngineModelInput,1>(
        UFG::qTreeRB<UFG::EngineModelOutput,UFG::EngineModelOutput,1> *this)
{
  UFG::qTreeRB<UFG::EngineModelInput,UFG::EngineModelInput,1>::DeleteAll(this);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)this);
}

// File Line: 187
// RVA: 0x676580
void __fastcall UFG::qTreeRB<UFG::VehicleEffectState,UFG::VehicleEffectState,1>::DeleteAll(
        UFG::qTreeRB<UFG::VehicleEffectState,UFG::VehicleEffectState,1> *this)
{
  Render::SkinningCacheNode *Head; // rbx

  while ( this->mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)this, &Head->mNode);
    if ( Head )
    {
      UFG::qTreeRB<UFG::VehicleEffect,UFG::VehicleEffect,1>::DeleteAll((UFG::qTreeRB<UFG::VehicleEffect,UFG::VehicleEffect,1> *)&Head[1]);
      UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&Head[1]);
      operator delete[](Head);
    }
  }
}

