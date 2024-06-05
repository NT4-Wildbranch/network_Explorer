// NT4.cpp : Defines the entry point for the application.
//



#include "NT4.h"
#include "include/HomeoStasis/c_Granulator.h"
#include "include/HomeoStasis/c_AE_Interface.h"
#include "include/c_Gaia.h"

using namespace std;











































                    

//Config.ssv - This file configures the network and sets the initial hyper-parameters. It handles the loading of any node files needed when using pretrained models.






//Input.ssv - This file holds the input data, each row an index

//Output.ssv - This file holds the output data, a table holding traces.

//This isn't for the engine itself, but for the testing of it. To remove in release version.
void generate_Test_Data()
{
    c_Sim Simboi;
    for (int cou_Index = 0; cou_Index < 100; cou_Index++)
    {
        Simboi.iterate();
        Simboi.output();
        Simboi.output_F("Sim_Test_Data.txt");
    }
}

int run_Flow_Visualizer()
{
    NT4::c_Construct_API NT4_Core;

    NT4_Core.register_Construct("1D_Pyramid", "Raw");

    std::string tmp_Input_0_Token;
    std::string tmp_Input;

    while (1)
    {
        std::cout << "\n\n Enter Input:";
        std::cin >> tmp_Input_0_Token;

        if (tmp_Input_0_Token == "-exit")
        {
            std::getline(cin, tmp_Input);
            break;
        }

        if (tmp_Input_0_Token == "<<")
        {
            NT4_Core.output_Scaffold_Symbols("Raw");
            continue;
        }

        if (tmp_Input_0_Token == "??")
        {
            std::getline(cin, tmp_Input);
            std::cout << "\n ... Wiping Network Charges";
            NT4_Core.wipe_Network_Charges();
            std::cout << "... Complete...";


            std::cout << "\n ... clear_Output";
            NT4_Core.clear_Output("Raw");
            std::cout << "... Complete...";

            std::cout << "\n ... reset_Input";
            NT4_Core.reset_Input("Raw");
            std::cout << "... Complete...";

            std::cout << "\n ... set_Input_String";
            NT4_Core.set_Input_String("Raw", tmp_Input);

            std::cout << "\n ... query";
            NT4_Core.query("Raw");
            std::cout << "... Complete...";

            std::cout << "\n ... gather_Treetops";
            NT4_Core.gather_Treetops("Raw");
            std::cout << "... Complete...";

            std::cout << "\n ... output_Output";
            NT4_Core.output_Output("Raw");
            std::cout << "... Complete...";

            std::ofstream SF;
            std::string tmp_SF_FName = "./Testing/Node_Network_Output/output_Traces/output_Traces.ssv";
            SF.open(tmp_SF_FName, std::ios::app);

            for (int cou_O = 0; cou_O < NT4_Core.get_Output_Depth("Raw"); cou_O++)
            {
                SF << cou_O << " ";
                std::string tmp_Pat = "";
                tmp_Pat = NT4_Core.get_Output_Pattern("Raw", cou_O);
                for (int cou_I = 0; cou_I < NT4_Core.get_Output_Pattern_Size("Raw", cou_O); cou_I++)
                {
                    SF << tmp_Pat[cou_I];
                }
                //std::cout << "\n";
                SF << "\n";
            }
            SF.close();
            NT4_Core.output_Network_Charges();
            continue;
        }

        if (tmp_Input_0_Token == "##")
        {
            uint64_t tmp_NID = 0;

            cin >> tmp_NID;

            NT4_Core.output_Node_Raw(tmp_NID);
            std::cout << "\n --- ";
            NT4_Core.output_Backpropagated_Symbol_NID(tmp_NID);

            continue;
        }

        if (tmp_Input_0_Token == "!!")
        {
            uint64_t tmp_Count = 3;

            int tmp_Height = 0;
            cin >> tmp_Height;

            std::ofstream SF;
            std::string tmp_SF_FName = "./Testing/Node_Network_Output/node_Charge_Output.ssv";
            SF.open(tmp_SF_FName, std::ios::app);

            for (int cou_C = 0; cou_C < tmp_Count; cou_C++)
            {
                SF << "\n";

                SF << tmp_Height << " ";

                for (int cou_I = 0; cou_I < NT4_Core.Base.Nodes.get_Fat_Tier(); cou_I++)
                {
                    SF << tmp_Height << " ";
                }
            }
            SF << "\n";
            SF.close();

            continue;
        }

        if (tmp_Input_0_Token == ">>apt")
        {
            double tmp_APT = 0.0f;

            std::cin >> tmp_APT;

            NT4_Core.set_Action_Potential_Threshold("Raw", tmp_APT);


            continue;
        }
        

        if (tmp_Input_0_Token == ">>mc")
        {
            double tmp_MC = 0.0f;

            std::cin >> tmp_MC;

            NT4_Core.set_Modifier_Charge("Raw", tmp_MC);


            continue;
        }

        std::getline(cin, tmp_Input);
        tmp_Input = tmp_Input_0_Token + " " + tmp_Input;
        
        NT4_Core.clear_Output("Raw");
        NT4_Core.reset_Input("Raw");
        NT4_Core.set_Input_String("Raw", tmp_Input);
        NT4_Core.encode("Raw");

        std::cout << "\n Node Count: " << NT4_Core.Base.Nodes.Node_Count;
        
    }
    
    return 1;
}

int main(int argc, char** argv)
{
    run_Flow_Visualizer();
    return 1;

    run_Gaia();
    //runmap();
    return 1;

    //NT4::c_GPT_4 GPT;
    NT4::c_GPT_5 GPT;

    GPT.run();


    /*
    uint64_t tmp_Data[5];
    NT4::c_Construct_API tmp_NT4;
    tmp_NT4.register_Construct("Many_To_One", "Raw");
    for (int cou_Index = 0; cou_Index < 100; cou_Index++)
    {
        tmp_Data[0] = 100;
        tmp_Data[1] = rand() % 10000;
        tmp_Data[2] = rand() % 10000;
        tmp_Data[3] = rand() % 10000;
        tmp_Data[4] = rand() % 10000;

        tmp_NT4.set_Input_uint("Raw", 5, tmp_Data);
        tmp_NT4.encode("Raw");
    }
    for (int cou_Index = 0; cou_Index < 100000; cou_Index++)
    {
        tmp_Data[0] = rand() % 10000;
        tmp_Data[1] = rand() % 10000;
        tmp_Data[2] = rand() % 10000;
        tmp_Data[3] = rand() % 10000;
        tmp_Data[4] = rand() % 10000;

        tmp_NT4.set_Input_uint("Raw", 5, tmp_Data);
        tmp_NT4.encode("Raw");
    }
    std::cout << "\n Query...";
    while (1)
    {
        tmp_Data[0] = 100;

        tmp_NT4.set_Input_uint("Raw", 1, tmp_Data);
        tmp_NT4.reset_Output("Raw");
        tmp_NT4.query("Raw");
        tmp_NT4.gather_Treetops("Raw");
    }

    */


    std::string tmp_Autoexec = "../autoexec.ssv";
    if (argc > 1) { tmp_Autoexec = argv[1]; }
    NT4::c_Construct_Text_Server Serverman(tmp_Autoexec);






    //generate_Test_Data();
    //system("PAUSE");

    Serverman.run();

	return 0;
}
