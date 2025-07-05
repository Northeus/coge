import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib.gridspec import GridSpec

data1 = np.random.rand(4, 3)
data2 = np.random.rand(4, 3)
data3 = np.random.rand(4, 3)

row_labels = ['deepseek-r1', 'gemma3', 'llama', 'bazmek']
col_labels = ['ALU', 'FSM', 'Bus']

titles = ['Best', 'Worst', 'Average']

fig = plt.figure(figsize=(12, 5), constrained_layout=True)
gs = GridSpec(1, 4, width_ratios=[1,1,1,0.05], wspace=0.3)
axes = [fig.add_subplot(gs[0, i]) for i in range(3)]

for i, data in enumerate([data1, data2, data3]):
    sns.heatmap(
        data,
        ax=axes[i],
        cbar=False,
        xticklabels=col_labels,
        yticklabels=row_labels,
        cmap='RdYlGn',
        annot=True,
        annot_kws={'weight': 'bold'},
        fmt=".1f",
        square=True
    )
    axes[i].set_title(titles[i], fontsize=14)
    axes[i].xaxis.set_label_position('top')
    axes[i].tick_params(axis='x', which='both', bottom=False, top=False, rotation=90, labelsize=12)
    axes[i].tick_params(axis='y', which='both', left=False, right=False, rotation=0, labelsize=12)
    axes[i].tick_params(bottom=False, top=False)
    axes[i].tick_params(labelleft=False)

axes[0].tick_params(labelleft=True)

im = axes[2].collections[0]
cbar_ax = fig.add_subplot(gs[0, 3])
cbar = fig.colorbar(im, cax=cbar_ax)
cbar.set_label('Accuracy (%)', fontsize=12, labelpad=8)
cbar.ax.yaxis.set_label_position('left')

plt.show()
