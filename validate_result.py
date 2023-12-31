FILENAME = "input-500.txt"
OUTPUT = "cxgiggeqsoduzbwkjcsfdhyvoukpfxqyrlcstpjhkkbsackkuoppywlybmgcyybemkcnvlxovqcynkvisxnplvbvjssnfchjidoexhkivmpkebmullkwindopiiwmnrfqcbyrutdfknuewfjlkrjulcrwmwnnbiemnfrextlkyspkalopusftcvuxftizronaireumgombedzyfimcrcabesvhbwujsooqqcvxpfwdbicdfvmeuexsrikdnefbsiosxgfpwxvlxujzumdefxikxepjmmtcsxuqwrmxlusfxuvzlarcvtorfyiyrfbkaxrwkwhnwcbnvhzcgltaffwfeakjgfopypyytdrfsqmtbkmsdwrjzgxahowupuglqfmvhqgraxzimtrjkmdwxmqnihlyjekoobdobykenlltzfdhmnjwcoitvevewefrrcrsjffjehseblizxcagvpgyyyenfhqdjxonsfdyxtqrzwqyazgqhsuihsrqvcouknokwuplbfiwnxwwkoiqacjjrhagpuhqudoefimhrrqnyogxcjzhtnchfrzxbhkthktvaeksprcefbmxjwtnlvldxcohaqpahulbfugmckcuwvaomzijjuexxkgkgkpsbbroxzcwlorezdqypdvnpswtnehwdiuxnhmnkrwgpjgrdasrpovjkqvuxjscwbwogooxhurywlwpmswqsqsukoroykhgoafvirwsbitygzervkxilhirmlzbywyqvjwtupwbyrkucvvojftawrzdyobxkvjjipdyhrpclklrlspxfzmsbokpvhvyrxgeelnqhqmdwdcvipwuathgmyblczmlmhxapvdtillavfcmynrzdjwvzgdfblenlmibpcdjrijmxdptqpperuuurltkaivpsylymzkvsipxkqmykctliholqjbiyfydhqihrtmakzomwmbdiinmkefaidflhrpexvfxcqsoojwmbklkiqpoujoccttdamligioiywgqowiicpakzwqqbxfoqacexdgwuqrtfexamimasebmwkmmosiupichqppbvbmubjcifsapynnzgwhnbcdnvzlaxmxlpsyffgnflxqcawonfgtasexprwqwpiidqvsqvdcrrmazgsymppzncwawaooccqmdkrmwnuefuvkoaxvmggwonjzieqomvtoznqnhrcnxbmhmnzzzrbgixxslpfombibtavpzemcilpbhohtrighguyuuvmrxumxsskdzjmiaiafkfsgtxnlwkciffvqpokxbnbkyubadgwisjyerpqnfnbxkaspwiykmpejbvewnkjeexvcwkccqaixjwqwkrchloujqquzzimmtzemkoylfjpqsjxngcebjgwjjuhgjtjxlwbdspzjachpqhetfkyelrtjjhpnxmjvnmftqtuknwczcjmkdzmdumbqlxsgzhwrhnbxsqsqrctdjqzzlgieihtsgdjxosncubzemhfegsixozfphbuwgavuoevyxheupshndjefdrraymdliqsssspviqvotzxvqddxnmqedeoqmraeqyozhzctufzslbjddsfwffqdsqhknbmvppbrnamehcbizoowbszqzqvzvqyjazptpiaxteuqaadqoeprpzsosqytetwnzenxuevstdoaftetwvgooofnbvebhwxheowwgxshlvjrxtwvjfaoxogpjdnfqdsvqcsdzszjklflggkrrtxqfgzeqxmnutxwdaoeajlnqvskfyvlzazanikeymthzalwhvwwlewstbgervvwjtomenphzvourjbhivlfuvupdnduzmqvxgvefuozzrvrhxvvrfmrokulydoguwzphurysjjkizqyhyqknztnhvcyrzaofqrczdmapykwjystgwlojalsycclqhzdhkmutxazceanxsmpjficijjqepjbyuiidejcejcewkzperdgclmvgeukqvljcojcntnelvpwotngjrbbyrehbpjywhqvticxevbxontwcdhkpcbecnmlcvxtefmsroyxfqiaotesesptgvtrvoduwdtzwmpzrlziwiwpvompr";
# 200 -> 863
# 500 -> 2112
# 1000 -> 4237
# 2000 -> 7708
# 4000 -> 15230
# 8000 -> 29270

file = open('./inputs/' + FILENAME, 'r')

lines = file.readlines()

valid = True;

for i in range(1, len(lines)):
    line = lines[i].strip()
    if line not in OUTPUT:
        valid = False
        print("Output does not contain " + line)

print("Output size is " + str(len(OUTPUT)))

if valid:
    print("Output is valid!")
else:
    print("Output is invalid!")