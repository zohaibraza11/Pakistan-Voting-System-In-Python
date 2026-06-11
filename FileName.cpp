# ============================================================
#   PAKISTAN ELECTRONIC VOTING SYSTEM
#   Professional Version
#   Language  : Python
#   Concepts : Lists, Functions, Loops, If / Else, I / O
# ============================================================

# ---- Constants ----
MAX_CANDIDATES = 5
MAX_VOTERS = 100

# ---- Candidate Data ----
candidateNames = [
    "Imran Khan",
    "Nawaz Sharif",
    "Bilawal Bhutto",
    "Siraj ul Haq",
    "Altaf Hussain"
]

partyNames = [
    "Pakistan Tehreek-e-Insaf",
    "Pakistan Muslim League (N)",
    "Pakistan Peoples Party",
    "Jamaat-e-Islami",
    "Muttahida Qaumi Movement"
]

partySymbols = [
    "Bat",
    "Lion",
    "Arrow",
    "Scale",
    "Kite"
]

votes = [0, 0, 0, 0, 0]

# ---- Voter Records ----
voterNames = []
voterCNICs = []
voterHasVoted = []
voterCount = 0

# ---- Admin Credentials ----
adminUsername = "admin"
adminPassword = "admin123"

# ---- Election Status ----
electionOpen = False

# ============================================================
#   HELPER FUNCTIONS
# ============================================================

def printLine(length = 60) :
    print("=" * length)

    def printDash(length = 60) :
    print("-" * length)

    def pressEnterToContinue() :
    input("\n  Press ENTER to continue...")

    def isValidCNIC(cnic) :
    if len(cnic) != 13 :
        return False
        for c in cnic :
if not c.isdigit() :
    return False
    return True

    def isCNICRegistered(cnic) :
    return cnic in voterCNICs

    def findVoterByCNIC(cnic) :
    for i in range(voterCount) :
        if voterCNICs[i] == cnic :
            return i
            return -1

            def getTotalVotes() :
            total = 0
            for i in range(MAX_CANDIDATES) :
                total += votes[i]
                return total

                def getWinnerIndex() :
                maxVotes = votes[0]
                winner = 0
                for i in range(1, MAX_CANDIDATES) :
                    if votes[i] > maxVotes:
maxVotes = votes[i]
winner = i
return winner

def maskCNIC(cnic) :
    # Show first 5 and last 1 digit only
    return cnic[:5] + "XXXXXXX" + cnic[12]

# ============================================================
    #   DISPLAY FUNCTIONS
# ============================================================

    def showBanner() :
    print("\n")
    printLine(60)
    print(f"{'        PAKISTAN ELECTRONIC VOTING SYSTEM':<60}")
    print(f"{'          Election Commission of Pakistan':<60}")
    printLine(60)
    print("\n")

    def showMainMenu() :
    print("\n")
    printLine(50)
    print("                    MAIN MENU")
    printLine(50)
    print("  1.  Voter Registration")
    print("  2.  Cast Your Vote")
    print("  3.  View Election Results")
    print("  4.  View Candidates List")
    print("  5.  View Registered Voters")
    print("  6.  Search Voter by CNIC")
    print("  7.  About This System")
    print("  8.  Admin Panel")
    print("  9.  Exit")
    printLine(50)

    def showCandidatesList() :
    print("\n")
    printLine(62)
    print("                  CANDIDATES LIST")
    printLine(62)
    print(f"{'No.':<4}{'Candidate Name':<18}{'Party':<28}{'Symbol'}")
    printDash(62)
    for i in range(MAX_CANDIDATES) :
        print(f"{i+1:<4}{candidateNames[i]:<18}{partyNames[i]:<28}{partySymbols[i]}")
        printLine(62)

# ============================================================
        #   VOTER REGISTRATION
# ============================================================

        def registerVoter() :
        global voterCount, voterNames, voterCNICs, voterHasVoted

        print("\n")
        printLine(50)
        print("              VOTER REGISTRATION")
        printLine(50)

        if voterCount >= MAX_VOTERS:
print("  [!] Maximum voter limit reached (100). Cannot register more.")
pressEnterToContinue()
return

print("  Enter your Full Name   : ", end = "")
name = input().strip()

if len(name) < 3:
print("  [!] Name must be at least 3 characters long.")
pressEnterToContinue()
return

print("  Enter your CNIC (13 digits, no dashes) : ", end = "")
cnic = input().strip()

if not isValidCNIC(cnic) :
    print("  [!] Invalid CNIC! Must be exactly 13 numeric digits.")
    pressEnterToContinue()
    return

    if isCNICRegistered(cnic) :
        print("  [!] This CNIC is already registered in the system.")
        pressEnterToContinue()
        return

        voterNames.append(name)
        voterCNICs.append(cnic)
        voterHasVoted.append(False)
        voterCount += 1

        print("\n")
        printDash(40)
        print("  Registration Successful!")
        printDash(40)
        print(f"  Name         : {name}")
        print(f"  CNIC         : {maskCNIC(cnic)}")
        print(f"  Voter Number : {voterCount}")
        printDash(40)

        pressEnterToContinue()

# ============================================================
        #   CAST VOTE
# ============================================================

        def castVote() :
        print("\n")
        printLine(50)
        print("                  CAST YOUR VOTE")
        printLine(50)

        if not electionOpen:
print("  [!] The election has not started yet.")
print("      Please contact the administrator.")
pressEnterToContinue()
return

if voterCount == 0:
print("  [!] No voters are registered in the system.")
pressEnterToContinue()
return

print("  Enter your CNIC (13 digits): ", end = "")
cnic = input().strip()

if not isValidCNIC(cnic) :
    print("  [!] Invalid CNIC format. Must be 13 numeric digits.")
    pressEnterToContinue()
    return

    voterIdx = findVoterByCNIC(cnic)

    if voterIdx == -1:
print("  [!] You are not registered in the system.")
print("      Please complete voter registration first.")
pressEnterToContinue()
return

if voterHasVoted[voterIdx]:
print("  [!] You have already cast your vote.")
print("      One CNIC is allowed only one vote.")
pressEnterToContinue()
return

print(f"\n  Voter Verified!")
print(f"  Welcome, {voterNames[voterIdx]}")

print("\n")
printLine(58)
print("                   BALLOT PAPER")
printLine(58)
print(f"{'No.':<4}{'Candidate Name':<18}{'Party'}")
printDash(58)
for i in range(MAX_CANDIDATES) :
    print(f"{i+1:<4}{candidateNames[i]:<18}{partyNames[i]}")
    printLine(58)

    try :
    choice = int(input(f"  Who would you like to vote for? (1-{MAX_CANDIDATES}): "))
    except :
    print(f"  [!] Invalid selection. Please enter a number between 1 and {MAX_CANDIDATES}.")
    pressEnterToContinue()
    return

    if choice < 1 or choice > MAX_CANDIDATES :
        print(f"  [!] Invalid selection. Please enter a number between 1 and {MAX_CANDIDATES}.")
        pressEnterToContinue()
        return

        print(f"\n  You selected  : {candidateNames[choice - 1]}")
        print(f"  Party         : {partyNames[choice - 1]}\n")
        print("  Confirm your vote? (1 = Yes / 2 = No): ", end = "")

        try :
        confirm = int(input())
        except :
        print("  Vote cancelled. No vote has been recorded.")
        pressEnterToContinue()
        return

        if confirm != 1 :
            print("  Vote cancelled. No vote has been recorded.")
            pressEnterToContinue()
            return

            votes[choice - 1] += 1
            voterHasVoted[voterIdx] = True

            print("\n")
            printLine(40)
            print("  Your vote has been cast successfully!")
            print("  Thank you for participating.          ")
            print("  Pakistan Zindabad!                    ")
            printLine(40)

            pressEnterToContinue()

# ============================================================
            #   SHOW RESULTS
# ============================================================

            def showResults() :
            print("\n")
            printLine(62)
            print("                  ELECTION RESULTS")
            printLine(62)

            total = getTotalVotes()
            print(f"  Total Votes Cast   : {total}")
            print(f"  Registered Voters  : {voterCount}")
            printDash(62)
            print(f"{'No.':<4}{'Candidate':<18}{'Votes':<8}{'%':<7}Bar Chart")
            printDash(62)

            for i in range(MAX_CANDIDATES) :
                percent = (votes[i] * 100.0 / total) if total > 0 else 0.0
                bars = int(percent / 4)

                print(f"{i+1:<4}{candidateNames[i]:<18}{votes[i]:<8}{percent:5.1f}% ", end = "")
                print("#" * bars)

                printLine(62)

                if total == 0:
print("  No votes have been cast yet.")
                else:
winnerIdx = getWinnerIndex()
winPct = (votes[winnerIdx] * 100.0) / total

print(f"\n  *** WINNER: {candidateNames[winnerIdx]} ***")
print(f"  Party  : {partyNames[winnerIdx]}")
print(f"  Votes  : {votes[winnerIdx]} ({winPct:.1f}%)")

printLine(62)
pressEnterToContinue()

# ============================================================
#   SHOW VOTERS LIST
# ============================================================

def showVotersList() :
    print("\n")
    printLine(58)
    print("              REGISTERED VOTERS LIST")
    printLine(58)

    if voterCount == 0:
print("  No voters are registered in the system.")
pressEnterToContinue()
return

print(f"  Total Registered Voters: {voterCount}")
printDash(58)
print(f"{'No.':<5}{'Full Name':<22}{'CNIC (Masked)':<16}{'Vote Status'}")
printDash(58)

for i in range(voterCount) :
    masked = voterCNICs[i][:5] + "XXXXX" + voterCNICs[i][10:13]
    status = "Voted" if voterHasVoted[i] else "Not Voted"
    print(f"{i+1:<5}{voterNames[i]:<22}{masked:<16}{status}")

    printLine(58)
    pressEnterToContinue()

# ============================================================
    #   SEARCH VOTER
# ============================================================

    def searchVoter() :
    print("\n")
    printLine(50)
    print("              SEARCH VOTER BY CNIC")
    printLine(50)

    if voterCount == 0:
print("  No voters are registered in the system.")
pressEnterToContinue()
return

print("  Enter CNIC (13 digits): ", end = "")
cnic = input().strip()

idx = findVoterByCNIC(cnic)

print("\n")
if idx == -1:
print("  [!] This CNIC is not registered in the system.")
else:
printDash(40)
print("  Voter Found!")
printDash(40)
print(f"  Voter Number  : {idx + 1}")
print(f"  Full Name     : {voterNames[idx]}")
print(f"  CNIC          : {maskCNIC(voterCNICs[idx])}")
print(f"  Vote Status   : {'Already Voted' if voterHasVoted[idx] else 'Has Not Voted Yet'}")
printDash(40)

pressEnterToContinue()

# ============================================================
#   ABOUT
# ============================================================

def showAbout() :
    print("\n")
    printLine(58)
    print("               ABOUT THIS SYSTEM")
    printLine(58)
    print("  System Name  : Pakistan Electronic Voting System")
    print("  Language     : Python")
    print("  Version      : Professional Edition")
    print("\n")
    print("  Features:")
    print("    - Voter Registration with CNIC validation")
    print("    - Secure Voting (One CNIC = One Vote)")
    print("    - Live Results with percentage bar chart")
    print("    - Candidates list with party and symbol")
    print("    - Registered voters list (masked CNIC)")
    print("    - Voter search by CNIC")
    print("    - Admin Panel (start / stop election)")
    print("    - Election statistics and turnout report")
    print("    - Admin password change")
    print("    - Votes reset functionality")
    print("\n")
    print("  Default Admin Credentials:")
    print("    Username : admin")
    print("    Password : admin123")
    printLine(58)
    pressEnterToContinue()

# ============================================================
    #   ADMIN PANEL
# ============================================================

    def adminStartElection() :
    global electionOpen

    if electionOpen :
        print("  [!] The election has already started.")
        elif voterCount == 0 :
        print("  [!] No voters are registered. Please register voters first.")
    else:
electionOpen = True
print(f"  [OK] Election has been STARTED successfully.")
print(f"       {voterCount} registered voter(s) may now cast their vote.")
pressEnterToContinue()

def adminStopElection() :
    global electionOpen

    if not electionOpen :
        print("  [!] The election is not currently running.")
    else :
        electionOpen = False
        print("  [OK] Election has been STOPPED.")
        print("       No further votes will be accepted.")
        pressEnterToContinue()

        def adminResetVotes() :
        global votes, voterHasVoted

        print("\n  WARNING: This will permanently delete ALL recorded votes!")
        print("  Type RESET to confirm: ", end = "")
        confirm = input().strip()

        if confirm == "RESET":
for i in range(MAX_CANDIDATES) :
    votes[i] = 0
    for i in range(voterCount) :
        voterHasVoted[i] = False
        print("  [OK] All votes have been reset. Voters may vote again.")
        else:
print("  Reset cancelled. No data has been changed.")
pressEnterToContinue()

def adminShowStats() :
    print("\n")
    printLine(50)
    print("             ELECTION STATISTICS")
    printLine(50)

    votedCount = 0
    for i in range(voterCount) :
        if voterHasVoted[i] :
            votedCount += 1

            notVoted = voterCount - votedCount
            turnout = (votedCount * 100.0 / voterCount) if voterCount > 0 else 0.0

            print(f"  Election Status    : {'OPEN' if electionOpen else 'CLOSED'}")
            print(f"  Registered Voters  : {voterCount}")
            print(f"  Votes Cast         : {votedCount}")
            print(f"  Did Not Vote       : {notVoted}")
            print(f"  Voter Turnout      : {turnout:.1f}%")
            print(f"  Total Votes        : {getTotalVotes()}")

            printDash(50)
            bars = int(turnout / 5)
            print(f"  Turnout  [{'#' * bars}{'-' * (20 - bars)}] {int(turnout)}%")

            printLine(50)
            pressEnterToContinue()

            def adminChangePassword() :
            global adminPassword

            print("\n")
            oldPass = input("  Enter Current Password    : ")

            if oldPass != adminPassword:
print("  [!] Incorrect password.")
pressEnterToContinue()
return

newPass = input("  Enter New Password        : ")

if len(newPass) < 6:
print("  [!] Password too short. Minimum 6 characters required.")
pressEnterToContinue()
return

confirmPass = input("  Confirm New Password      : ")

if newPass != confirmPass:
print("  [!] Passwords do not match.")
pressEnterToContinue()
return

adminPassword = newPass
print("  [OK] Password changed successfully.")
pressEnterToContinue()

def adminPanel() :
    print("\n")
    printLine(45)
    print("                ADMIN LOGIN")
    printLine(45)

    username = input("  Username : ").strip()
    password = input("  Password : ").strip()

    if username != adminUsername or password != adminPassword:
print("  [!] Invalid credentials. Access denied.")
pressEnterToContinue()
return

print("  [OK] Login successful. Welcome, Administrator.\n")

while True:
printLine(46)
print("                 ADMIN PANEL")
printLine(46)
print("  1.  Start Election")
print("  2.  Stop Election")
print("  3.  View Statistics")
print("  4.  Reset All Votes")
print("  5.  Change Admin Password")
print("  6.  View Candidates List")
print("  7.  Back to Main Menu")
printLine(46)

try :
    choice = int(input("  Enter choice (1-7): "))
    except :
    print("  [!] Invalid input. Please enter a number.")
    continue

    if choice == 1 :
        adminStartElection()
        elif choice == 2 :
        adminStopElection()
        elif choice == 3 :
        adminShowStats()
        elif choice == 4 :
        adminResetVotes()
        elif choice == 5 :
        adminChangePassword()
        elif choice == 6 :
        showCandidatesList()
        pressEnterToContinue()
        elif choice == 7 :
        print("  Returning to main menu...")
        break
    else:
print("  [!] Invalid choice. Please enter 1-7.")

# ============================================================
#   MAIN
# ============================================================

def main() :
    showBanner()

    print("  Welcome to the Pakistan Electronic Voting System!")
    print("  Before voting begins, please log in to the Admin Panel")
    print("  and start the election (Admin > Start Election).\n")
    print("  Default credentials -> Username: admin | Password: admin123\n")

    while True:
showMainMenu()
try :
    choice = int(input("  Enter your choice (1-9): "))
    except :
    print("  [!] Invalid input. Please enter a number between 1 and 9.")
    continue

    if choice == 1 :
        registerVoter()
        elif choice == 2 :
        castVote()
        elif choice == 3 :
        showResults()
        elif choice == 4 :
        showCandidatesList()
        pressEnterToContinue()
        elif choice == 5 :
        showVotersList()
        elif choice == 6 :
        searchVoter()
        elif choice == 7 :
        showAbout()
        elif choice == 8 :
        adminPanel()
        elif choice == 9 :
        print("\n")
        printLine(40)
        print("  Thank you for using this system.")
        print("  Pakistan Zindabad!")
        printLine(40)
        break
    else:
print("  [!] Invalid choice. Please enter a number between 1 and 9.")

if __name__ == "__main__" :
    main()