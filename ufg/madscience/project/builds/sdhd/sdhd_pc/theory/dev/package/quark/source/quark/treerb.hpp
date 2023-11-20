// File Line: 173
// RVA: 0x66BF60
void __fastcall UFG::qTreeRB<UFG::EngineModelInput,UFG::EngineModelInput,1>::~qTreeRB<UFG::EngineModelInput,UFG::EngineModelInput,1>(UFG::qTreeRB<UFG::EngineModelOutput,UFG::EngineModelOutput,1> *this)
{
  Render::Skinning *v1; // rbx

  v1 = (Render::Skinning *)this;
  UFG::qTreeRB<UFG::EngineModelInput,UFG::EngineModelInput,1>::DeleteAll(this);
  UFG::qBaseTreeRB::~qBaseTreeRB(v1);
}

// File Line: 187
// RVA: 0x676580
void __fastcall UFG::qTreeRB<UFG::VehicleEffectState,UFG::VehicleEffectState,1>::DeleteAll(UFG::qTreeRB<UFG::VehicleEffectState,UFG::VehicleEffectState,1> *this)
{
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v1; // rsi
  Render::SkinningCacheNode *v2; // rbx

  v1 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this;
  if ( this->mTree.mCount )
  {
    do
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v1);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mTree, &v2->mNode);
      if ( v2 )
      {
        UFG::qTreeRB<UFG::VehicleEffect,UFG::VehicleEffect,1>::DeleteAll((UFG::qTreeRB<UFG::VehicleEffect,UFG::VehicleEffect,1> *)&v2[1]);
        UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v2[1]);
        operator delete[](v2);
      }
    }
    while ( v1->mTree.mCount );
  }
}

