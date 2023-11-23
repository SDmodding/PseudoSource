// File Line: 8
// RVA: 0x49DAC0
void __fastcall UFG::ProgressionTracker::DrawMissionWorkStates(UFG::ProgressionTracker *this, float realTimeDelta)
{
  UFG::GameSlice *mpActiveMaster; // rbx
  float mSecondsLeftToDisplayFor; // xmm2_4
  UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *p_mMissionStates; // rbp
  Render::DebugDrawContext *Context; // rsi
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *mNext; // rbx
  int v7; // edi

  mpActiveMaster = this->mpActiveMaster;
  if ( mpActiveMaster )
  {
    if ( mpActiveMaster->mType == (NUM_TYPES|TYPE_OCCLUSION|0x8) )
    {
      mSecondsLeftToDisplayFor = mpActiveMaster->mSecondsLeftToDisplayFor;
      if ( mSecondsLeftToDisplayFor > 0.0 )
      {
        mpActiveMaster->mSecondsLeftToDisplayFor = mSecondsLeftToDisplayFor - realTimeDelta;
        p_mMissionStates = &mpActiveMaster->mMissionStates;
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                3u);
        Render::DebugDrawContext::DrawTextA(
          Context,
          70,
          75,
          &UFG::qColour::White,
          "%s Work States",
          mpActiveMaster->mTitle.mText);
        mNext = mpActiveMaster->mMissionStates.mNode.mNext;
        if ( mNext == (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)p_mMissionStates )
        {
          Render::DebugDrawContext::DrawTextA(Context, 70, 90, &UFG::qColour::White, "None");
        }
        else
        {
          v7 = 90;
          do
          {
            Render::DebugDrawContext::DrawTextA(
              Context,
              70,
              v7,
              &UFG::qColour::White,
              "%s : %s",
              (const char *)mNext[2].mNext,
              (const char *)mNext[5].mPrev);
            mNext = mNext->mNext;
            v7 += 15;
          }
          while ( mNext != (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)p_mMissionStates );
        }
      }
    }
  }
}

