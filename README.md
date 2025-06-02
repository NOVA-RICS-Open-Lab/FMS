<div  align="center"> 

# Open Modular Controller for Automation Technologies
[![License: MIT](https://img.shields.io/badge/License-MIT-red.svg)](https://opensource.org/licenses/MIT)
[![DOI](https://img.shields.io/badge/DOI-ICPS_2024-darkblue)](https://doi.org/10.1109/ICPS59941.2024.10639979)
[![NOVA SST: Thesis](https://img.shields.io/badge/NOVA_SST-Thesis-blue)](https://run.unl.pt/handle/10362/175433)

[Joao Potier](https://pt.linkedin.com/in/jo%C3%A3o-potier-5b1301228?trk=public_profile_samename-profile)<sup>1</sup>, 
[Miguel Arvana](https://scholar.google.com/citations?user=UBvr388AAAAJ&hl=pt-PT)<sup>1</sup>,
[Leandro Filipe](https://scholar.google.pt/citations?user=SoIohJwAAAAJ&hl=en)<sup>1</sup>,
[Fabio M-Oliveira](https://www.researchgate.net/profile/Fabio-M-Oliveira)<sup>1</sup>,
[Andre Rocha](https://scholar.google.pt/citations?user=k1GIyqcAAAAJ&hl=pt-PT)<sup>1</sup>,
[Jose Barata](https://scholar.google.pt/citations?user=4G8tKCsAAAAJ&hl=en)<sup>1</sup>

<sup>1</sup> **NOVA School of Science and Technology, Center of Technology and Systems (UNINOVA-CTS)**,
and Associated Lab of Intelligent Systems (LASI), NOVA University
Lisbon, 2829-516 Lisbon, Portugal

<table>
  <tr>
    <td style="vertical-align: top;">
      This work proposes the development of a controller, with modularity and flexibility as the core ideas, that allows for the integration of open-source standards like the proprietary technologies used in emergent factories and automation technologies. The implementation of this architecture led to the development of a prototype modular industrial controller that is, on average, a quarter of the cost of the new generation of industrial controllers. The developed controller was tested and validated using some educational kits.
    </td>
    <td style="vertical-align: top;">
      <img style="width: 1100px" src="imgs/Sensores.jpg" alt="pcb" width="200"/>
    </td>
  </tr>
</table>

</div>

## <div align="center">Get Started</div>
Follow these steps to setup the FMS-Kit controller and digital twin:

1. **Industrial Shields 57R+**
   
    In order to use the controller, the correct board package must be installed in your Arduino IDE. This can be done in 2 ways:
   1. Arduino way
      - Inside your Arduino IDE, go to *Preferences*
      - Copy the link ```http://apps.industrialshields.com/main/arduino/boards/package_industrialshields_index.json``` to your *Additional boards manager URLs* parameter.
      - Save and exit
   2. Repository way
      - Place the libraries found in the repository at [libraries](./src/Arduino/libraries/) inside your arduino libraries folder.
      - Place Industrial Shields boards package found in the repository at [package](./src/Arduino/boards%20package/) in your arduino package's folder.

    To complete the setup

   - Open your *Boards Manager* (Ctrl + Shift + B)
   - Install the ```industrialshields-avr``` boards package.
   - Select the ```M-Duino family``` board.
   - Select the ```M-Duino 57R+``` model.
   - Locate the developed Arduino Code in the repository [here](./src/Arduino/KIT_FMS_DigitalShadow/KIT_FMS_DigitalShadow.ino).
   - Edit the IP configuration present in the start of the code to your desired configuration.
   - Upload the code to the controller.

1. **HMI App Instalation**
   - Locate the Kit FMS APK files in the repository at [Kit FMS.apk](./src/HMI/Kit%20FMS.apk).
   - Execute apk in a android mobile device of your choosing.

2. **Digital Twin Deployment**
  
   - Execute the file Kit FMS.exe in the repository at [Kit FMS.exe](./src/Unity/Exec/Kit%20FMS.exe).
   

3. **IP Configuration**

  1. HMI IPs

      - In the DT, press "DEBUG" in the top left corner.
      - In the HMI, press "CHANGE IP", place the IP found in the DT's DEBUG Interface.

  2. DT IPs

      - In the DT, press "SETTINGS" in the top left corner.
      - Place the "TABLET IP" found in your mobile device. 
      - Place the "Arduino IP" found in your controller's arduino code. 

If all steps are followed, your system is now ready for operation.

---

[FAZER SEMPRE QUE É DESLIGADO O KIT FMS/INTELLIJ]

## Usage instructions

### Everytime the system is turned off

  1. Start Kit FMS DT
  2. Start Kit FMS HMI
  3. Open the Agents IntelliJ Project found in the repository at [](./src/Agents/CTS_Andre)
  4. Run the Agents Program
  6. In the Kit FMS DT, press "CONNECT" on the top left corner
  
> **NOTE:** In order to verify the setup, go to the "DEBUG" menu in the DT and see that both Agents and Tablet status are "ON".

### How to launch a product ?

1. No tablet, dizer em que lado se encontra o operador.
2. No KIT FMS do PC, no canto superior esquerdo clicar no botão "SETUP", dizer quais Skills estão disponiveis em que operadores.
3. No KIT FMS do PC, no canto superior esquerdo clicar no botão "LAUNCH", dizer quais as ações que quer que aconteça no bloco. (O Kit fisico não gosta muito de dar voltas com uma só peça e fica preso nos sitios, é recomendado meter as duas peças na mesma volta)
4. Quando pedido, clicar o tablet a dizer que foi colocada uma peça.

Follow these guidelines, and your project should operate as expected!

---

### Project Structure
For you to better understand this repository organization, here is a quick overview of its structure and where to find what you might be looking for:
```
FMS
├── docs                            # documentation assets
│   └── paper.pdf                       # related investigation work
├── imgs                            # images from this project
├── src                             # developed code
│   ├── Agents                          # Multi Agent System code
│   │   ├── CTS_Andre                       # developed agents intelij project
│   │   └── jade                            # agents library
│   ├── Arduino                         # Industrial Shields 57+ arduino code
│   │   ├── KIT_FMS_DigitalShadow           # arduino code
│   │   └── libs                            # arduino libraries
│   ├── DT                              # DT code
│   │   ├── Exec                            # DT executable
│   │   └── Source                          # DT Unity project
│   └── HMI                             # HMI code
│       ├── Kit FMS                         # HMI apk
│       └── HMIUnity                        # HMI Unity project
└── README                              # this document
```

## <div align="center">Documentation</div>
The [docs](./docs/) directory contains related investigation work conducted on the implemented system

## <div align="center">Contribution Guidelines</div>
NOVA RICS Open Lab open source, and we welcome contributions from the community! See the [Contribution](CONTRIBUTING.md) guide for more information on the development workflow and the internals of the wandb library. For project related bugs and feature requests, visit [GitHub Issues](https://github.com/NOVA-RICS-Open-Lab/open-modular-controller/issues) or contact novaricsopenlab@gmail.com

## <div align="center">Citation</div>
If you use or intend to build on top of  the work in this repo, please consider citing our project:
```bibtex
@inproceedings{10639979,
  author={Potier, João and Arvana, Miguel and Filipe, Leandro and M-Oliveira, Fabio and Rocha, Andre Dionisio and Barata, Jose},
  booktitle={2024 IEEE 7th International Conference on Industrial Cyber-Physical Systems (ICPS)}, 
  title={Development of an Open, Modular Controller for Training in Emergent Automation Technologies}, 
  year={2024},
  doi={10.1109/ICPS59941.2024.10639979}
}
```

## <div align="center">License</div>
This repository is released under the MIT License. Please see the [LICENSE](LICENSE) file for more details.

## <div align="center">Contacts</div>
For any questions regarding this or any other project please contact us at novaricsopenlab@gmail.com or enroll in our [Discussion Forum](https://github.com/NOVA-RICS-Open-Lab/open-modular-controller/discussions) for sharing your ideas and sharing projects.

% AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
% AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
% AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
% AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
% AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
% AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

### =[COMO CORRER]=


CONCLUIDO



CONCLUIDO

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Comunicações
### Arduino -> Unity
[Isto serve para trocar bits no Unity]
Socket com Json\
Ip da Unity -> localhost:8888\
Exemplo de Json:\
{\
 "Port" : "R1_0",\
 "Value" : "1"\
}

### HMI -> Unity
[Isto serve para adicionar um bloco na caixa da Unity]
HTTP Post com Json\
Ip da Unity -> http://localhost:8082/ \
Exemplo de Json:\
{\
 "Position" : "1",\
 "Color" : "Red"\
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Sensores I Number_Index
| Number | Index | Function         | Active |
|--------|-------|------------------|--------|
| 0      | 0     | Conveyor B       | High   |
| 0      | 1     | Conveyor A       | High   |
| 0      | 2     | Punch Down       | Low    |
| 0      | 3     | Punch Up         | Low    |
| 0      | 4     | Punch Forward    | High   |
| 0      | 5     | Punch Backward   | High   |
| 1      | 0     | Conveyor C       | High   |
| 1      | 1     | Conveyor D       | High   |
| 1      | 2     | Rotate E Give    | Low    |
| 1      | 3     | Rotate E Receive | Low    |
| 1      | 4     | Rotate C Give    | Low    |
| 1      | 5     | Rotate C Receive | Low    |
| 2      | 0     | Conveyor E       | High   |
| 2      | 1     | Conveyor F       | High   |
| 2      | 2     | Conveyor A Left  | Low    |
| 2      | 3     | Conveyor A Right | Low    |
| 2      | 4     | -                | -      |
| 2      | 5     | -                | -      |

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Atuadores R Number_Index
| Number | Index | Function             |
|--------|-------|----------------------|
| 0      | 0     | -                    |
| 0      | 1     | -                    |
| 0      | 2     | Punch Up             |
| 0      | 3     | Punch Forward        |
| 0      | 4     | Conveyor E           |
| 0      | 5     | Conveyor E Receive   |
| 0      | 6     | Conveyor C Give      |
| 0      | 7     | Conveyor A Backwards |
| 0      | 8     | Conveyor A Right     |
| 1      | 0     | -                    |
| 1      | 1     | -                    |
| 1      | 2     | -                    |
| 1      | 3     | Punch Down           |
| 1      | 4     | Conveyor F           |
| 1      | 5     | Rotate C Give        |
| 1      | 6     | Conveyor C           |
| 1      | 7     | Conveyor B           |
| 1      | 8     | Conveyor A Left      |
| 2      | 3     | Punch Spin           |
| 2      | 4     | Punch Forward        |
| 2      | 5     | -                    |
| 2      | 6     | Conveyor D           |
| 2      | 7     | Conveyor C Receive   |
| 2      | 8     | Conveyor A Forward   |

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Serviços

Kit_FMS_M-Duino
EX: 192.168.2.28/passadeiras?skill=AB
IP:192.168.2.28
Serviços:
/passadeiras skill: AB BC CD DE EF FA
/estacao skill: 2-> calibrate 1-> screw 0->drll
