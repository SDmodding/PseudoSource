// File Line: 8
// RVA: 0x49DAC0
void __fastcall UFG::ProgressionTracker::DrawMissionWorkStates(UFG::ProgressionTracker *this, float realTimeDelta)
{
  UFG::GameSlice *v2; // rbx
  float v3; // xmm2_4
  signed __int64 v4; // rbp
  Render::DebugDrawContext *v5; // rsi
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *v6; // rbx
  int v7; // edi

  v2 = this->mpActiveMaster;
  if ( v2 )
  {
    if ( v2->mType == 11 )
    {
      v3 = v2->mSecondsLeftToDisplayFor;
      if ( v3 > 0.0 )
      {
        v2->mSecondsLeftToDisplayFor = v3 - realTimeDelta;
        v4 = (signed __int64)&v2->mMissionStates;
        v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
        Render::DebugDrawContext::DrawTextA(v5, 70, 75, &UFG::qColour::White, "%s Work States", v2->mTitle.mText);
        v6 = v2->mMissionStates.mNode.mNext;
        if ( v6 == (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)v4 )
        {
          Render::DebugDrawContext::DrawTextA(v5, 70, 90, &UFG::qColour::White, "None");
        }
        else
        {
          v7 = 90;
          do
          {
            Render::DebugDrawContext::DrawTextA(v5, 70, v7, &UFG::qColour::White, "%s : %s", v6[2].mNext, v6[5].mPrev);
            v6 = v6->mNext;
            v7 += 15;
          }
          while ( v6 != (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)v4 );
        }
      }
    }
  }
}

