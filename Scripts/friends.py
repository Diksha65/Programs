import os, random, sys

#change the path to the folder where friends is present
path = "/media/diksha/BUBBLES/Leisure Time/series/Friends"
os.chdir(path)

#function to select a random friends season
def getRandomFile(path):
    files = os.listdir(path)
    index = random.randrange(0, len(files))
    return files[index]

#change the path to that season
os.chdir(getRandomFile(path))

new_path = os.getcwd()

media_list = []
srt_list=[]

def create_media_list():
    for files in os.walk(new_path):
        for file in files:
            if(file.lower().endswith('.mkv', 'avi')):
                media_list.append(os.path.join(new_path, file))
            if(file.lower().endswith('.srt')):
                srt_list.append(os.path.join(new_path, file))

def select_random_file():
    create_media_list()
    media = random.choice(media_list)
    ''' f not srt_list:
        for srt in srt_list:
            if(srt.lower().startwith(media[:15])):
                srtfile = srt '''
    return media

print(select_random_file())
def play_episode():
    media, srt = select_random_file()

