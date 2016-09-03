cmake_minimum_required(VERSION 3.6)
project(Algorithms-Advanced)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# Basic - 2015.2

# AD-HOC I - Contest: http://ahmed-aly.com/contest?ID=23613
add_executable(Bingo Basic/ad-hoc/Bingo.cpp)
add_executable(KiloMan Basic/ad-hoc/KiloMan.cpp)
add_executable(InBraille Basic/ad-hoc/InBraille.cpp)
add_executable(HitTheTarget Basic/ad-hoc/HitTheTarget.cpp)
add_executable(LinelandMail Basic/ad-hoc/LinelandMail.cpp)
add_executable(DifferentDigits Basic/ad-hoc/DifferentDigits.cpp)
add_executable(TanyaAndPostcard Basic/ad-hoc/TanyaAndPostcard.cpp)
add_executable(DivisionOfNlogonia Basic/ad-hoc/DivisionOfNlogonia.cpp)

# AD-HOC II - Contest: http://ahmed-aly.com/contest?ID=23764
add_executable(Stripe Basic/ad-hoc/Stripe.cpp)
add_executable(Resort Basic/ad-hoc/Resort.cpp)
add_executable(BallsGame Basic/ad-hoc/BallsGame.cpp)
add_executable(BooksCatalog Basic/ad-hoc/BooksCatalog.cpp)
add_executable(KefaAndCompany Basic/ad-hoc/KefaAndCompany.cpp)
add_executable(LaserSculpture Basic/ad-hoc/LaserSculpture.cpp)
add_executable(WhereAreMyKeys Basic/ad-hoc/WhereAreMyKeys.cpp)
add_executable(BeautifulSetsOfPoints Basic/ad-hoc/BeautifulSetsOfPoints.cpp)

# Bônus - Contest: http://ahmed-aly.com/contest?ID=23919
add_executable(Tri-du Basic/bonus/Tri-du.cpp)
add_executable(Feynman Basic/bonus/Feynman.cpp)
add_executable(MusicalLoop Basic/bonus/MusicalLoop.cpp)
add_executable(KickbackSum Basic/bonus/KickbackSum.cpp)
add_executable(IdentifyingTea Basic/bonus/IdentifyingTea.cpp)
add_executable(HoursAndMinutes Basic/bonus/HoursAndMinutes.cpp)
add_executable(TheClubBallroom Basic/bonus/TheClubBallroom.cpp)
add_executable(ContractRevision Basic/bonus/ContractRevision.cpp)

# Estruturas de Dados - Contest: http://ahmed-aly.com/contest?ID=24051
add_executable(Rails Basic/structures/Rails.cpp)
add_executable(Subsequences Basic/structures/Subsequences.cpp)
add_executable(BrokenKeyboard Basic/structures/BrokenKeyboard.cpp)
add_executable(HallOfMurderesrs Basic/structures/HallOfMurderers.cpp)
add_executable(WhereIsTheMarble Basic/structures/WhereIsTheMarble.cpp)
add_executable(ParenthesisBalanceI Basic/structures/ParenthesisBalanceI.cpp)
add_executable(MishaAndChangingHandles Basic/structures/MishaAndChangingHandles.cpp)
add_executable(ICanGuessTheDataStructure Basic/structures/ICanGuessTheDataStructure.cpp)

# Problem Solving - Contest: http://ahmed-aly.com/contest?ID=24200
add_executable(Team Basic/problem-solving/Team.cpp)
add_executable(TShirts Basic/problem-solving/TShirts.cpp)
add_executable(DiamondsAndSand Basic/problem-solving/DiamondsAndSand.cpp)
add_executable(AnyaAndSmartphone Basic/problem-solving/AnyaAndSmartphone.cpp)
add_executable(BiggestNumberGame Basic/problem-solving/BiggestNumberGame.cpp)
add_executable(HammingDistanceSum Basic/problem-solving/HammingDistanceSum.cpp)
add_executable(NewYearAndOldProperty Basic/problem-solving/NewYearAndOldProperty.cpp)
add_executable(PuttingPlatesOnTheTuk-tuks Basic/problem-solving/PuttingPlatesOnTheTuk-tuks.cpp)

# Matemática - Contest: http://ahmed-aly.com/contest?ID=24306
add_executable(DuffInLove Basic/math/DuffInLove.cpp)
add_executable(VanyaAndBooks Basic/math/VanyaAndBooks.cpp)
add_executable(AllYouNeedIsLove Basic/math/AllYouNeedIsLove.cpp)
add_executable(VasyaAndPetyasGame Basic/math/VasyaAndPetyasGame.cpp)
add_executable(SimpleBaseConversion Basic/math/SimpleBaseConversion.cpp)
add_executable(SoldierAndNumberGame Basic/math/SoldierAndNumberGame.cpp)
add_executable(MarianneAndTheTwinCousins Basic/math/MarianneAndTheTwinCousins.cpp)
add_executable(TrinomialTriangleTheRevenge Basic/math/TrinomialTriangleTheRevenge.cpp)

# Revisão I - Contest: http://ahmed-aly.com/contest?ID=24473
add_executable(BerSUBall Basic/review/BerSUBall.cpp)
add_executable(SimpleGame Basic/review/SimpleGame.cpp)
add_executable(Permutation Basic/review/Permutation.cpp)
add_executable(PashaAndTea Basic/review/PashaAndTea.cpp)
add_executable(CaseOfMatryoshkas Basic/review/CaseOfMatryoshkas.cpp)
add_executable(RenzoPalindromicDecoration Basic/review/RenzoPalindromicDecoration.cpp)

# Grafos I  - Contest: http://ahmed-aly.com/standings?ID=24617
add_executable(IsItATree Basic/graphs/IsItATree.cpp)
add_executable(SmartGame Basic/graphs/SmartGame.cpp)
add_executable(TwoButtons Basic/graphs/TwoButtons.cpp)
add_executable(CopsAndRobbers Basic/graphs/CopsAndRobbers.cpp)
add_executable(DuduServiceMaker Basic/graphs/DuduServiceMaker.cpp)
add_executable(ValeraAndElections Basic/graphs/ValeraAndElections.cpp)
add_executable(ConnectedComponents Basic/graphs/ConnectedComponents.cpp)

# Grafos II - Contest: http://ahmed-aly.com/contest?ID=24874
add_executable(DarkRoads Basic/graphs/DarksRoads.cpp)
add_executable(EvenObsession Basic/graphs/EvenObsession.cpp)

# Guloso e Backtracking - Contest: https://ahmed-aly.com/contest?ID=25006
add_executable(FindingTeamMember Basic/greedy-and-backtracking/FindingTeamMember.cpp)

# Revisão II - Contest: http://ahmed-aly.com/contest?ID=25290
add_executable(Fence Basic/review/Fence.cpp)
add_executable(AmrAndPins Basic/review/AmrAndPins.cpp)


# Intermediary - 2016.1

# SQRT Decomposition
add_executable(DQuery Intermediary/sqrt-decomposition/DQuery.cpp)
add_executable(Collector Intermediary/sqrt-decomposition/Collector.cpp)
add_executable(HorribleQueries Intermediary/sqrt-decomposition/HorribleQueries.cpp)
add_executable(PowerfulArray Intermediary/sqrt-decomposition/PowerfulArray.cpp)
add_executable(LittleElephantAndArray Intermediary/sqrt-decomposition/LittleElephantAndArray.cpp)

# Segment Tree
add_executable(Census Intermediary/segment-tree/Census.cpp)
add_executable(ToPoland Intermediary/segment-tree/ToPoland.cpp)
add_executable(MaximumSum Intermediary/segment-tree/MaximumSum.cpp)
add_executable(IntervalProduct Intermediary/segment-tree/IntervalProduct.cpp)
add_executable(CanYouAnswerTheseQueries Intermediary/segment-tree/CanYouAnswerTheseQueries.cpp)

# Lowest Common Ancestor
add_executable(Trucks Intermediary/lowest-common-ancestor/Trucks.cpp)
add_executable(AntsColony Intermediary/lowest-common-ancestor/AntsColony.cpp)
add_executable(DuffInTheArmy Intermediary/lowest-common-ancestor/DuffInTheArmy.cpp)
add_executable(LowestCommonAncestor Intermediary/lowest-common-ancestor/LowestCommonAncestor.cpp)

# Max Flow
add_executable(TotalFlow Intermediary/max-flow/TotalFlow.cpp)
add_executable(AngryProgrammer Intermediary/max-flow/AngryProgrammer.cpp)
add_executable(PowerTransmission Intermediary/max-flow/PowerTransmission.cpp)
add_executable(InternetBandwidth Intermediary/max-flow/InternetBandwidth.cpp)

# Fast Flow
add_executable(DungeonOfDeath Intermediary/fast-flow/DungeonOfDeath.cpp)
add_executable(MyTshirtSuitsMe Intermediary/fast-flow/MyTshirtSuitsMe.cpp)
add_executable(FastMaximumFlow Intermediary/fast-flow/FastMaximumFlow.cpp)

# Number Theory
add_executable(EuclidProblem Intermediary/number-theory/EuclidProblem.cpp)
add_executable(CrucialEquation Intermediary/number-theory/CrucialEquation.cpp)
add_executable(MediumFactorization Intermediary/number-theory/MediumFactorization.cpp)
add_executable(SequenceSumPossibilities Intermediary/number-theory/SequenceSumPossibilities.cpp)
add_executable(QuidEstVeritasEstVirQuiAdest Intermediary/number-theory/QuidEstVeritasEstVirQuiAdest.cpp)