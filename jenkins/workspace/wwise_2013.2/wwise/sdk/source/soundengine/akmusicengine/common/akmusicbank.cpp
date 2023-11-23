// File Line: 32
// RVA: 0xAAD780
__int64 __fastcall AkMusicBank::LoadBankItem(
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot,
        unsigned int in_dwBankID)
{
  CAkIndexItem<CAkFxShareSet *> *v5; // rax
  CAkIndexItem<CAkFxShareSet *> *v7; // rax
  CAkIndexItem<CAkFxShareSet *> *NodeLock; // rax

  switch ( in_rSection->eHircType )
  {
    case 0xA:
      NodeLock = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
      return CAkBankMgr::StdBankRead<CAkMusicSegment,CAkParameterNodeBase>(
               g_pBankManager,
               in_rSection,
               in_pUsageSlot,
               NodeLock);
    case 0xB:
      return CAkBankMgr::ReadSourceParent<CAkMusicTrack>(g_pBankManager, in_rSection, in_pUsageSlot, in_dwBankID);
    case 0xC:
      v7 = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
      return CAkBankMgr::StdBankRead<CAkMusicSwitchCntr,CAkParameterNodeBase>(
               g_pBankManager,
               in_rSection,
               in_pUsageSlot,
               v7);
    case 0xD:
      v5 = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
      return CAkBankMgr::StdBankRead<CAkMusicRanSeqCntr,CAkParameterNodeBase>(
               g_pBankManager,
               in_rSection,
               in_pUsageSlot,
               v5);
    default:
      return 3i64;
  }
}

